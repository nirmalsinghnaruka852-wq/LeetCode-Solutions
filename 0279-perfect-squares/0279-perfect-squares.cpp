
using vi = vector<int>;

class Solution {
public:
   vi dp ;
   int dfs(int remaning){
    if(remaning <= 0 ) return remaning == 0 ? 0  : INT_MAX  ;
    else if(dp[remaning] != -1 ) return dp[remaning];
    int ans = INT_MAX ;
    for(int i = 1 ; i*i <= remaning ; i++){
       int res = INT_MAX;
       res =  dfs(remaning - (i* i));
      if(res != INT_MAX) ans = min(ans , res+1 );
    }
    return dp[remaning] = ans ; 
   }
    int numSquares(int n) {
        dp.resize(n+1 , -1 );
        int ans = dfs(n ) ;

        return ans == INT_MAX  ? 1 : ans ;
    }
};