class Solution {
public:
    bool isSubsequence(string s, string t){
       int lastIndex = 0 ;
        for(int index = 0 ; index < s.length() ; index++ ){
        while(lastIndex < t.size() && t[lastIndex] != s[index]) lastIndex++ ;
        if(lastIndex == t.size()|| t[lastIndex] != s[index] ) return false ;
        lastIndex++ ;  
        } 
        return true ;
    }
};