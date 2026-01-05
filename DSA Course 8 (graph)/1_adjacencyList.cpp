#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
template <typename T>

class Graph{
  public:
    unordered_map<T, list<T>> adj;
    void addEdge(T u, T v, bool direction){
      // direction : 0 - undirected, 1 - directed
      adj[u].push_back(v);
      if(direction == 0)
        adj[v].push_back(u);
    }

    void printAdjList(){
      for(auto i: adj){
        cout<<i.first<<" -> ";
        for(auto j: i.second)
          cout<<j<<", ";
        cout<<endl;
      }
    }
};

int main(){
  int n, m;
  cout<<"Enter the number of nodes: ";
  cin>> n;
  cout<<"Enter the number of edges: ";
  cin>> m;
  
  Graph<int> g;
  for(int i = 0; i<m; i++){
    int u, v;
    cin>>u>>v;
    g.addEdge(u, v, 0);
  }
  g.printAdjList();
  return 0;
}


/*
  Enter the number of nodes: 5
  Enter the number of edges: 6
  0 1
  1 2
  1 3
  2 3
  3 4
  4 0

  
 */