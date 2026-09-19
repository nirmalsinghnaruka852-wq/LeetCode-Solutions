using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vvi result;
    vi ans;
    void solve(int currentIndex, vi& nums) {
        if (currentIndex >= nums.size()) {
            result.push_back(ans);
            return;
        }
        // skip
        solve(currentIndex + 1, nums);
        ans.push_back(nums[currentIndex]);
        // take
        solve(currentIndex + 1, nums);
        ans.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) { 
        solve(0 , nums );
        return result; }
};