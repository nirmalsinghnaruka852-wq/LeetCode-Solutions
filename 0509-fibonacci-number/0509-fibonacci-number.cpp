class Solution {
public:
//   tablization ;
    int fib(int n) {
      if(n <= 1) return n ; 
      int prev = 0 ;
      int nextprev = 1 ; 
      int newElement = 0 ; 
       for(int i = 2 ; i <= n ; i++){
       newElement = prev + nextprev ;  
        prev = nextprev ;
       nextprev  =  newElement;
       
       } 
       return  newElement ; 
    }
};