using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
   vvi dp ;
    int solve(int left , int right , string& s ){
        if(left > right ) return 0 ; 
        if(dp[left][right] != -1) return dp[left][right];
        int ans = INT_MAX ; 
        if(s[left] == s[right] ) ans = solve(left+1 , right -1 , s );
        else {
            ans = min(ans ,min( 1 + solve(left+ 1 , right , s ) , 1+ solve(left , right -1 , s )));
        }
        return dp[left][right] = ans ; 
    }
    
    int minInsertions(string s) {
        int n = s.size() ;
        dp.resize(n , vi(n , - 1));
        return solve(0 , n -1 , s );
        
    }
};