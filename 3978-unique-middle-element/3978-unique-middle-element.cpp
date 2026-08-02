class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
      int n = nums.size() ;
     int mid =  floor(nums.size()/2);
      for(int index = 0 ; index < n ; index++ ){
        if(index == mid) continue ;
        else if(nums[index] == nums[mid ]) return false ;
      }
      return true ; 
    }
};