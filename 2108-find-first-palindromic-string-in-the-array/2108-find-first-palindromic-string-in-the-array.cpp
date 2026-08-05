class Solution {
public:
    bool check(string s ){
      int i = 0 ;
      int  j = s.size()-1 ;
      while(i <= j ){
        if(s[i] != s[j] ) return false ;
        i++ ;
        j-- ;
      }
      return true ; 
    }
    string firstPalindrome(vector<string>& words) {
      for(int index = 0 ; index < words.size() ; index++ ){
        if(check(words[index])) return words[index] ; 
      }
        return "";
    }
};