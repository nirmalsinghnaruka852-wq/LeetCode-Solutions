class Solution {
public:
    long long maximumValue(int n, int s, int m) {
      // n = 4 
      if(n == 1 ) return s ;
    int space = n -1 ;
  return s +(ceil(space /2.0) * m) - floor(space / 2) +( n%2 == 1 ? + 1 : 0 );
    }
  
};