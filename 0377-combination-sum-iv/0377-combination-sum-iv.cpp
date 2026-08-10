class Solution {
public:
    vector<int>dp; 
     int dfs(int currIndex , int remaning , vector<int>&nums){
      if(remaning <= 0 ) return remaning == 0 ? 1 : 0 ;
      if(dp[remaning] !=  -1 ) return dp[remaning];
      int ans = 0 ; 
      for(int index = 0 ; index < nums.size() ; index++){
        ans += dfs(index , remaning - nums[index] , nums);
      }
      return dp[remaning] = ans ; 
     }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1 , -1 );
        return dfs(0 , target , nums);
       }
};