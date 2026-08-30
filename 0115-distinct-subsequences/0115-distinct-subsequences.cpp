class Solution {
public:
    int n;
    int m ;
    vector<vector<int>>dp ;
    int dfs(int i  , int j , string& s , string& t ){
      if( j >= m ) return 1 ;
      else if(i >= n ) return 0 ;
      else if(dp[i][j] != -1 ) return dp[i][j];
       int sum = 0 ;
      if(s[i] == t[j]) sum += dfs(i+1 , j+1 , s , t );
        sum+= dfs(i+1 , j , s , t); 
        return dp[i][j] = sum ;
    }
    int numDistinct(string s, string t) {
      n =  s.size() ;
      m = t.size() ;
      dp.resize(n , vector<int>( m , -1));
      return dfs(0 , 0 , s , t);
    }
};