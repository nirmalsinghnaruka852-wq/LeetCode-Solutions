class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> dp;
    long long  dfs(int index, string &s) {
        if (index >= s.size())
            return 1;
        if (s[index] == '0')
            return 0;
        if(dp[index] != -1 ) return dp[index];
        long long  takeOne = 0 ;
        long long  takeTwo = 0;
         if (s[index] == '*') takeOne = (9LL * dfs(index + 1, s)) % MOD;
        else  takeOne = dfs(index + 1, s);
        
        if (index + 1 < s.size()) {

            if (s[index] == '*' && s[index + 1] == '*') {
                takeTwo = (15LL * dfs(index + 2, s)) % MOD;
            }

            else if (s[index + 1] == '*') {

                if (s[index] == '1')
                    takeTwo = (9LL * dfs(index + 2, s))% MOD;
                else if (s[index] == '2')
                    takeTwo = (6LL * dfs(index + 2, s))% MOD ;
            }

            else {

                if (s[index] == '*') {

                    if (s[index + 1] <= '6')
                        takeTwo = (2LL * dfs(index + 2, s)) % MOD;
                    else
                        takeTwo = dfs(index + 2, s);

                }

                else {

                    int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

                    if (num >= 10 && num <= 26)
                        takeTwo = dfs(index + 2, s);
                }
            }
        }
        return   dp[index] = (takeOne + takeTwo) % MOD;; 
    }
    int numDecodings(string s){
   dp.assign(s.size(), -1);
      return dfs(0 , s ); 
    }
};