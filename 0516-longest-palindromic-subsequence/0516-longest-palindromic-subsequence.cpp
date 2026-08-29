using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    // int n;
    vvi dp ; 
    int dfs(int i, int j, string& s) {
       if(i > j ) return 0 ;
      if (i == j) return 1;
      if(dp[i][j] != -1 ) return dp[i][j];
      if(s[i]== s[j]) 
      return dp[i][j] = 2 + dfs(i+1 , j -1 , s );
      return dp[i][j] = max(dfs(i+1 , j , s ) ,dfs(i , j -1 , s ) );
    }
    int longestPalindromeSubseq(string s) {
      int n = s.size() ;
      dp.resize(n , vi(n  , -1 ));
      return dfs(0 , n-1 , s);
    }
};