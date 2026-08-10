class Solution {
public:
    int finder(vector<int>& nums, int k) {
    int start = 0;
    unordered_map<int, int> freq;
    int distinct = 0;
    int ans = 0;

    for (int end = 0; end < nums.size(); end++) {

        if (freq[nums[end]] == 0)
            distinct++;

        freq[nums[end]]++;

        while (distinct > k) {
            freq[nums[start]]--;

            if (freq[nums[start]] == 0)
                distinct--;

            start++;
        }

        ans += end - start + 1;
    }

    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return finder(nums, k) - finder(nums, k - 1);
        ;
    }
};
