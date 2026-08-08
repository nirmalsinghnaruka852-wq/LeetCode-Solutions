class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int total0Have = 0 ;
     int  i = 0 ;
      int MaxLength = 0 ; 
     for(int index = 0 ; index < nums.size() ; index++){
      if(nums[index] == 0 ) total0Have++ ;
      while(total0Have > k){
          if(nums[i] == 0  ) total0Have-- ;
          i++; 
      }
       MaxLength = max(MaxLength , (index - i)+ 1);
     }   
     return MaxLength; 
    }
};