class Solution {
public:
  vector<int>dp ;
    int dfs(int remaning , vector<int>& coins ){
      if(remaning == 0 ) return 0 ;
      else if(remaning < 0 ) return INT_MAX ;
      else if(dp[remaning] != -1 ) return dp[remaning];
      int ans  = INT_MAX ; 
      for(int coin : coins ){
      int res = dfs(remaning - coin , coins);
       if (res != INT_MAX )
             ans = min(res+1 , ans);
      }
      return dp[remaning] =  ans ; 
    }
    int coinChange(vector<int>& coins, int amount) {
       dp.resize(amount + 1  , -1 );
       int ans = dfs(amount , coins ) ;
       return ans == INT_MAX ? -1 : ans ;  
    }
}; 