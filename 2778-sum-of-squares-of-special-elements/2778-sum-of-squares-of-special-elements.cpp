class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n= nums.size() ;
        int sum = 0  ; 
        for(int index = 0 ; index < n; index++  ){
            int i = index+1 ; 
          if(  n % i  == 0 ) sum += nums[index] * nums[index];
        }
        return sum ;
    }
};