class Solution {
public:
  vector<vector<int>>dp ; 
  int total ; 
   int dfs(int index , int currSum , int target,vector<int>& nums){
    if(index == nums.size() ) return currSum == target ? 1 : 0 ; 
    if(dp[index][currSum+ total] != -1 ) return dp[index][currSum+ total];
    int way = dfs(index+1 , currSum - nums[index] , target , nums)+ 
    dfs(index+1 , currSum + nums[index] , target , nums);
    return dp[index][currSum+ total] = way ; 
   }
    int findTargetSumWays(vector<int>& nums, int target) {
      int n = nums.size() ;
      total = accumulate(nums.begin(), nums.end(), 0);
      dp.resize(n , vector<int>(total*2 +1 , -1));
      return dfs(0 , 0 , target, nums);
        
    }
};