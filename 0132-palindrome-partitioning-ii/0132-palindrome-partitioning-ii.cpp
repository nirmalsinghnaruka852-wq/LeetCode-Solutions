using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    // 1. the first question is u have to make the all posblie paildrome string
    // as a true ;
    // 2. create all possible substring which is paildrome and return minOne ;
    int n;
    vvi dp;
    vi dp1 ; 
    bool vaildPalindrome(int i , int j){
      return dp[i][j];
    }
    int minimumCutPalindrome(int currentIndex , string& s ){
      if(currentIndex >= n ) return 0 ;
      if(dp1[currentIndex] != INT_MAX ) return dp1[currentIndex];
      int MinOne = INT_MAX; 
      for(int index = currentIndex ; index < n ; index++ ){
       if(vaildPalindrome(currentIndex , index))
       {int cut =  0 ; 
         if(index == n-1 )  cut = 0 ;
          else  cut  = 1+ minimumCutPalindrome(index+1 , s );
           MinOne = min(MinOne ,cut );}
      }
      return dp1[currentIndex] = MinOne;
    }

    int minCut(string s) {
        n = s.size();
        dp.resize(n, vi(n, false));
        dp1.resize(n , INT_MAX);
        for (int length = 0; length < n; length++) {
            for (int i = 0; i < n; i++) {
                int j = i + length;
                if (j >= n)
                    break;
                if (length == 0)
                    dp[i][j] = true;
                else if (length == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        
        return minimumCutPalindrome(0 , s ); 
    }
};