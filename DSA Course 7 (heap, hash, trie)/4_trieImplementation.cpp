#include<iostream>
using namespace std;

class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char c){
      data = c;
      for(int i = 0; i<26; i++){
        children[i] = NULL;
      }
      isTerminal = false;
    }
};

class Trie {
  public:
    TrieNode* root;
    Trie(){
      root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){
      // base case
      if(word.length() == 0){
        root->isTerminal = true;
        return;
      }

      // assuming incoming words are in caps
      int index = word[0] - 'A';
      TrieNode* child;
      // for first char
      if(root->children[index] != NULL)     // char present
        child = root->children[index];
      else{                                 // char absent
        child = new TrieNode(word[0]);
        root->children[index] = child;
      }
      // for next chars
      insertUtil(child, word.substr(1));       // sending the extracted string (after removing first char)
    }

    void insertWord(string word){
      insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
      // base case
      if(word.length() == 0)
        return root->isTerminal;

      int index = word[0] - 'A';
      TrieNode* child;
      if(root->children[index] != NULL)     // present
        child = root->children[index];
      else                                  // absent
        return false;

      // for rest of chars
      return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
      return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
      // base case
      if(word.length() == 0){
        root->isTerminal = false;
        return;
      }

      int index = word[0] - 'A';
      TrieNode* child;
      if(root->children[index] != NULL)     // present
        child = root->children[index];
      else                                  // absent
        return;

      // for rest of chars
      removeUtil(child, word.substr(1));
    }

    void removeWord(string word){
      removeUtil(root, word);
    }

};

int main(){
  Trie* t = new Trie();
  t->insertWord("ARM");
  t->insertWord("TIME");
  t->insertWord("DO");
  cout<<t->searchWord("TIME")<<endl;
  t->removeWord("ARM");
  cout<<t->searchWord("ARM")<<endl;
  t->insertWord("ARMY");
  cout<<t->searchWord("ARMY")<<endl;
  t->insertWord("ARM");
  cout<<t->searchWord("ARM")<<endl;
  t->removeWord("ARMY");
  cout<<t->searchWord("ARMY")<<endl;
  return 0;
}