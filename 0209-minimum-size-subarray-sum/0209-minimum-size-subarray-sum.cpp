class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int sum = 0 ; 
      int i = 0 ;
      int MinLength = INT_MAX ; 
    for(int index = 0 ; index < nums.size() ; index++){
        sum += nums[index];
        while(sum >= target){
          MinLength = min(MinLength ,(index - i)+1 );
          sum-=nums[i++];
        }
    }        
    return MinLength == INT_MAX ? 0 : MinLength;
    }
};
