class Solution {
public:
   vector<int>dp; 
    int dfs(int index, string s) {
        if (index >= s.size())
            return 1;
        if (s[index] == '0')
            return 0;
        if(dp[index] != -1) return dp[index];
        // if(index == s.size() -1 ) return 1 ;
        int takeOne = dfs(index + 1, s);
        if (index + 1 < s.size() && (s[index] == '1' ||
            (s[index] == '2' && s[index + 1] <= '6')))
            takeOne += dfs(index + 2, s);
        return dp[index ] = takeOne;
    }

    int numDecodings(string s) {
        // return 0 ;
        dp.resize(s.size() , -1 ); 
        return dfs(0, s);
    }
};