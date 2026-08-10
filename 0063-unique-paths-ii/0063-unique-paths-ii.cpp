class Solution {
public:
   vector<vector<int>>dp ;
   int dfs(int row , int col , int m , int n ,vector<vector<int>>& obstacleGrid ){
    if(row >= m || col >= n || row < 0 || col < 0 ||obstacleGrid[row][col] ==1  ) return 0 ;
    if(row == m-1 && col == n-1 ) return 1 ;
    if(dp[row][col] != -1 ) return dp[row][col];
    int bottom = dfs(row +1 , col , m , n ,obstacleGrid );
    int top = dfs(row ,col +1 , m , n , obstacleGrid);
    return dp[row][col] = top + bottom ; 
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m =  obstacleGrid.size() ;
      int n = obstacleGrid[0].size() ; 
        dp.resize(m , vector<int>(n ,-1));
        return dfs(0 , 0 , m , n , obstacleGrid);
    }
}; 