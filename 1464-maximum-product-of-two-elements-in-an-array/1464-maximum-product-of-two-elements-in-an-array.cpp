class Solution {
public:
    int maxProduct(vector<int>& nums){
      int first = INT_MIN , second = INT_MIN ;
      for(int index = 0 ; index < nums.size() ; index++){
        int n = nums[index];
        if(n > first){
          int temp = n ;
           n = first ;
           first = temp ; 
        }
        if(n > second) second = n ; 
      }
        return (first - 1) * (second - 1);
    }
};