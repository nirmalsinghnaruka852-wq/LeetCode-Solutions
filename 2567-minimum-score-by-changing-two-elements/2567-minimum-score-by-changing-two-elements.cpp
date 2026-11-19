
using vi = vector<int>;

class Solution {
public:
    vi Sort(vi left, vi right) {
        vi ans;
        int i = 0, j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) ans.push_back(left[i++]);
            else ans.push_back(right[j++]);
        }

        while (i < left.size()) ans.push_back(left[i++]);
        while (j < right.size()) ans.push_back(right[j++]);

        return ans;
    }

    vi merge(int startIndex, int endIndex, vi& nums) {
        if (startIndex == endIndex) return {nums[startIndex]};

        int mid = startIndex + (endIndex - startIndex) / 2;

        return Sort(
            merge(startIndex, mid, nums),
            merge(mid + 1, endIndex, nums)
        );
    }

    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) return 0;

        sort(nums.begin() ,nums.end());

        int ans = INT_MAX;

        ans = min(ans, nums[n - 1] - nums[2]);
        ans = min(ans, nums[n - 2] - nums[1]);
        ans = min(ans, nums[n - 3] - nums[0]);

        return ans;
    }
};
