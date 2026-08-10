class Solution {
public:
    vector<int>dp;

    int dfs(int curr , int size , set<string>& st , string s ){
      if(curr >= size) return 1 ;
      if(dp[curr] != -1) return dp[curr];
       string match = "";
       bool ans = false ;
       for(int index = curr ; index < size ; index++){
        match += s[index];
        if(st.count(match)) ans = ans || dfs(index + 1 , size , st , s );
       }
       return dp[curr] = ans ? 1 : 0 ; 
    }
    bool wordBreak(string s, vector<string>& wordDict){
      int n = s.size() ;
      dp.resize(n , -1);
      set<string>st;
      for(string word : wordDict){
        st.insert(word);
      }
        return dfs( 0 , n , st , s ) ==1 ? true : false ; 
    }
};