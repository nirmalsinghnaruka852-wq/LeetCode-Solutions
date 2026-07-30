class Solution {
public:
    int minimumPushes(string word) {
      cout << word.size() ; 
      // if(word.size() == 26 ) return 51;
    if(word.size() <= 8 ) return word.size();
     else if(word.size() <= 16 ){
      int HowMuch = word.size() - 8 ;
      return 8 + HowMuch * 2 ; 
    }
  else if(word.size() <= 24 ){
    int hoMuch = word.size() - 16 ;
    return 8 + 16 + hoMuch * 3 ;
  } 
   int hoMuch = word.size() - 24 ;
   return 48 + hoMuch * 4 ; 
    }
};