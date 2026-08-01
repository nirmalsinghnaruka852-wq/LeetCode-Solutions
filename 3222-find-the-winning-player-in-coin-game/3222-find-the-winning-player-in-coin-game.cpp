class Solution {
public:
  bool dfs(int x , int y ){
    if(x < 1 ||  y < 4) return false ;
    return !dfs(x - 1 , y - 4);
  }
    string winningPlayer(int x, int y) {
        return dfs(x , y ) ? "Alice": "Bob"; 
    }
};