using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vvi ans ;
    vi path ; 
    int n ;  
    void dfs(int startIndex , vi& nums ){
      ans.push_back(path);
      for(int i = startIndex  ; i < n ; i++  ){
        if (i > startIndex && nums[i] == nums[i - 1])
                continue;
        path.push_back(nums[i]);
         dfs(i + 1 , nums );
         path.pop_back() ; 
      }
      return ;

    }
 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      n = nums.size() ; 
       sort(nums.begin(), nums.end());

        dfs(0 , nums);

        return ans;
    }
};