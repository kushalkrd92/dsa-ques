#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited){
  if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (arr[x][y] == 1))
    return true;
  return false;
}

void findPath(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, string path, vector<string> &ans){
  if(x == n-1 && y == n-1){
    ans.push_back(path);
    return;
  }

  visited[x][y] = 1;
  // down
  if(isSafe(x+1, y, arr, n, visited))
    findPath(x+1, y, arr, n, visited, path + "D", ans);
  // left
  if(isSafe(x, y-1, arr, n, visited))
    findPath(x, y-1, arr, n, visited, path + "L", ans);
  // right
  if(isSafe(x, y+1, arr, n, visited))
    findPath(x, y+1, arr, n, visited, path + "R", ans);
  // up
  if(isSafe(x-1, y, arr, n, visited))
    findPath(x-1, y, arr, n, visited, path + "U", ans);

  visited[x][y] = 0;
}

int main(){
  vector<vector<int>> arr = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
  int n = arr.size();
  vector<vector<bool>> visited(n, vector<bool> (n, 0));
  int x = 0, y = 0;
  string path = "";
  vector<string> ans;
  if(arr[0][0] == 0){
    cout<<" ";
    return 0;
  }
  findPath(x, y, arr, n, visited, path, ans);
  for(int i = 0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
  return 0;
}