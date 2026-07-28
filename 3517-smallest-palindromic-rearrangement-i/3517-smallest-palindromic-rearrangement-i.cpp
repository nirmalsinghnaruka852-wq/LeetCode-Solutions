using vi = vector<int>;
class Solution {
public:
    string smallestPalindrome(string s) {
        vi count(26 , 0 );
        for(char ch : s ){
          int index = ch - 'a';
          count[index]++ ;
        }
        string firstSection = "";
        int oddIndex =  -1 ;
        for(int index =  0 ; index < 26 ; index++){
          while(count[index] > 1 ){
            firstSection  += (char)(index + 'a');
            count[index]-=2 ; 
          } 
          if(count[index] == 1 ) oddIndex = index ;
        }
        string lastSection = firstSection ;
        string ans = "";
           reverse(lastSection.begin() , lastSection.end()); 
      if(oddIndex != -1 ) ans = firstSection + (char)(oddIndex + 'a') + lastSection; 
      else ans = firstSection + lastSection ;  
      return ans ;
    }
    
};
  