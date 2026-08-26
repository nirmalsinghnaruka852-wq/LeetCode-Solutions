class Solution {
public:
    bool check(string& s2 , string& part ){
      int i  = s2.size() -1; 
       int j = part.size() -1;
       while(i >= 0  && j >= 0 ){
        if(s2[i] != part[j] ) return false ;
        i-- ;
        j-- ; 
       } 
     return true ; 
    }
    string removeOccurrences(string s, string part) {
        // u just have a loop on the s ;
        // inside this u have to make a string like s1 and  also check like that
        // size() >= part ; if yes then it have the part from the right if yes
        // and then remove it ; at the last u have to return the s2 ok ;
        string s2 = "";
        int n = s.size() ;
        int m = part.size() ;
        for(int index = 0 ; index < n ; index++ ){
          s2 += s[index];
          if(s2.size() >= m && s2[s2.size() -1 ] == part[m-1]){
            if(check(s2 , part)){
               for(int index = 0 ; index < m ; index++){
                s2.pop_back() ; 
               }
            }
          }
        }
        return s2 ; 
    }
};