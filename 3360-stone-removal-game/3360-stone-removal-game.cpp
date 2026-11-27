class Solution {
public:
    bool canAliceWin(int n) {
       char currentChanes = 'A';
        int total = 10 ; 
        while( n >= 0 ){
            currentChanes = currentChanes  == 'B'? 'A' : 'B' ;
            n =  n - total ;
            total-- ; 
   
        }
      return currentChanes == 'A' ; 
    }
};