class Solution {
public:
vector<int>dp ; 
   int dfs(int n , int limit ){
    if(n >= limit) return n == limit ? 1 : 0 ;
     if(dp[n] != -1 ) return dp[n];
    return dp[n] = dfs(n+1 , limit) + dfs(n+2 , limit ); 
   }
    int climbStairs(int n) {
      dp.resize(n+1  , -1 ); 
        return dfs(0 , n);
    }
};