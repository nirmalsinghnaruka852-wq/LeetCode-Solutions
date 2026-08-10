class Solution {
public:
   vector<vector<int>>dp; 
     int dfs(int currIndex , int remaning , vector<int>&nums){
      if(remaning <= 0 ) return remaning == 0 ? 1 : 0 ;
      if(dp[currIndex][remaning] !=  -1 ) return dp[currIndex][remaning];
      int ans = 0 ; 
      for(int index = 0 ; index < nums.size() ; index++){
        ans += dfs(index , remaning - nums[index] , nums);
      }
      return dp[currIndex][remaning] = ans ; 
     }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(nums.size() , vector<int>(target+1 , -1 ));
        return dfs(0 , target , nums);
       }
};