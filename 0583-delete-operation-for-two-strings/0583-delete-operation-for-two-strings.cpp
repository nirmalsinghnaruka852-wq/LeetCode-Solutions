using vi = vector<int> ;
using vvi = vector<vi>;
class Solution {
public:
int n  ;
   int m  ; 
    vvi dp ; 
   int VaildLongestPossibleSubsequence(int i , int j , string& t1 , string& t2){
    if(i >= n || j >= m ) return (i >= n ) ? m - j : n- i ;
     if (dp[i][j] != -1 ) return dp[i][j];
    if(t1[i] == t2[j]) return dp[i][j]  =  VaildLongestPossibleSubsequence(i+1 , j+1 , t1 , t2 );
     return dp[i][j] = 1 + min(VaildLongestPossibleSubsequence(i , j+1 , t1 , t2 )
        , VaildLongestPossibleSubsequence(i+1 , j , t1 , t2 ));
   }
    int minDistance(string word1, string word2) {
        n = word1.size() ;
        m = word2.size() ;
        dp.resize(n , vi(m , -1 ));
        return VaildLongestPossibleSubsequence( 0 , 0 , word1 , word2);
    }
};