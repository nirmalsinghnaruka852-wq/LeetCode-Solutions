using vi = vector<int>;
class Solution {
public:
    vi frequency ;
    int ans = 0 ; 
   void  countAllPossibiletile(){
      for(int index = 0; index < 26 ; index++ ){
        if(frequency[index] == 0 ) continue ;
        ans++ ;
        frequency[index]-- ;
        countAllPossibiletile() ; 
        frequency[index]++;

      }
      return ;  
    } 
    int numTilePossibilities(string tiles) {
         frequency.resize(26  , 0);
         for(char ch : tiles){
          int index = ch - 'A';
          frequency[index]++ ;
         }
        countAllPossibiletile() ;
        return ans ; 
    }
};
