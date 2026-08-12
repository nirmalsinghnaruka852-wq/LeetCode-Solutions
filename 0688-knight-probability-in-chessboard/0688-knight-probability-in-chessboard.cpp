class Solution {
public:
  vector<vector<vector<double>>>dp ;
  vector<pair<int , int >>moves= {
    //  all 8 moves ;
      {-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1}
  };
   double dfs(int row , int col , int move , int n ){
    if(row < 0 || col < 0|| row >= n || col >= n ) return 0.00 ;
    if(move == 0 ) return 1.00 ;
    if(dp[row][col][move] != -1 ) return dp[row][col][move];
    double ans = 0.00 ;
    for(pair<int , int>& dir : moves ){
      int r1 = row + dir.first ;
      int c1 = col + dir.second ;
        ans += dfs(r1 , c1 , move-1 , n );
    }
    ans = ans /8.00 ; 
    return dp[row][col][move] =ans ;
   }
     double knightProbability(int n, int k, int row, int column) {
     dp.resize(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));  
     return dfs(row , column , k , n );
    }
};