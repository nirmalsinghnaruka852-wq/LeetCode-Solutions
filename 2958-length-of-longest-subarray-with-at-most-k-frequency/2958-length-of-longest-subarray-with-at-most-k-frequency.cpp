class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0;
        // int diciet = 0;
        int ans = 0;
        unordered_map<int, int> feq;
        for (int end = 0; end < n; end++) {
            
                feq[nums[end]]++;
  
            while (feq[nums[end]] > k) {
                feq[nums[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};