class Solution {
public:
    bool checkString(string s) {
       // if any a occure after a b then return false ;
       bool aOccur  = false ; 
       bool bOccur  =  false ;
       for(int index = 0 ; index < s.size() ; index++){
        if(s[index]== 'a' && bOccur ) return false ;
         if(s[index]== 'a') aOccur = true  ;
         else  bOccur  =  true ; 
       }
       return true ; 
    }
};