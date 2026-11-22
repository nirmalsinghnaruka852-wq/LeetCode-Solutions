class Solution {
public:
    bool checkString(string s) {
       // if any a occure after a b then return false ;
       bool aOccur  = false ; 
       bool bOccur  =  false ;
       for(int index = 0 ; index < s.size() ; index++){
        if(s[index]== 'a' && bOccur ) return false ;
         else if(s[index]== 'b' && !bOccur )  bOccur  =  true ; 
       }
       return true ; 
    }
};

//  TC-O(N);
//  SC-O(1);
// time - less then 1 sec ;
//  memory for space alloaction -> 0 MB;