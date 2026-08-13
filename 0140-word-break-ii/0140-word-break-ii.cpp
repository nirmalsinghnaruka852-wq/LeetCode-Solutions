class Solution {
public:
    vector<string>ans ; 
     void dfs(int curretIndex , string s , set<string>&s2 , string s3 = ""){
      if(curretIndex >= s.size() ){
        s3.pop_back();
        ans.push_back(s3);
        return ;
      } 
      string ans = "";
      for(int index = curretIndex ; index < s.size() ; index++){
          ans+=s[index];
          if(s2.count(ans)) dfs(index+1 , s , s2 , s3 + ans+ " ");
      } 
      return ; 
     }
    vector<string> wordBreak(string s, vector<string>& wordDict){
      set<string>s2;
      for(int index = 0 ;index < wordDict.size() ; index++ ){
           s2.insert(wordDict[index]);
      }
      dfs(0 , s , s2 );
     return ans ;    
    }
};