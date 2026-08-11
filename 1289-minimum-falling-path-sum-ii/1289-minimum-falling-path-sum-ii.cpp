class Solution {
public:
    vector<vector<int>>dp ;
    int dfs(int row , int col , vector<vector<int>>& grid ){
      if(col < 0 || col >= grid[row].size()) return INT_MAX ;
      if(row == grid.size() -1 ) return grid[row][col];
      if(dp[row][col] != INT_MAX) return dp[row][col];
      int minOne = INT_MAX ; 
     for(int newCol = 0 ; newCol < grid[row].size() ; newCol++){
      if(newCol == col ) continue ;
      int m = dfs(row +1 , newCol , grid );
      if(m != INT_MAX ) m += grid[row][col];
      minOne = min(minOne , m ) ;
     }
      return dp[row][col] = minOne;
    }
    int minFallingPathSum(vector<vector<int>>& grid){
      int n = grid.size() ;
      int m = grid[0].size() ;
      int minOne = INT_MAX ; 
      dp.resize(n , vector<int>(m , INT_MAX));
      for(int i = 0 ; i < n ; i++){
       minOne =  min(minOne ,dfs(0 , i , grid ));
      }
      return minOne; 
        
    }
};