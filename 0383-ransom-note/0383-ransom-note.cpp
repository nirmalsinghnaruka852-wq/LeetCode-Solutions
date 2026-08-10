class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    //  create the fequence arr of the magazine ;
    // for each char of the ransomeNote check thers is <=1 if not return false ;
    //  else return true ; 
   vector<int>feq(26 , 0 );
   for(char ch : magazine){
    int index = ch-'a';
    feq[index]++ ; 
   }
   for(int ch : ransomNote){
    int index= ch -'a';
    if(feq[index] < 1) return false ;
    feq[index]--;
   }
   return true ;

    }
};