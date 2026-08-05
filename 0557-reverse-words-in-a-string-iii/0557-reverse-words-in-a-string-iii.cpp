class Solution {
public:
    string reverseWords(string s){
      string ans = "" ;
      string current = "";
      for(int index = 0 ; index < s.size() ; index++ ){
        if(s[index] == ' '){
          ans +=   current + " " ;
          current  = ""; 
        }
        else current = s[index] + current;
      }
      return ans+ current;
        
    }
};