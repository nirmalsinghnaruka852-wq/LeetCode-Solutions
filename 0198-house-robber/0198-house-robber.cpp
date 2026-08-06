using vi = vector<int>;
class Solution {
public:
   vi dp ; 
  int dfs(int index , vi&nums){
    //  base case ;
    if(index >= nums.size() ) return 0 ; 
    if(dp[index] != -1 ) return dp[index];
    int take = nums[index] + dfs(index+2 ,nums);
     int notTake = dfs(index+1 , nums);
     return dp[index] =  max(take , notTake );
  }
    int rob(vector<int>& nums) {
      dp.resize(nums.size() , -1 );
     return dfs(0 ,  nums);
    }
};