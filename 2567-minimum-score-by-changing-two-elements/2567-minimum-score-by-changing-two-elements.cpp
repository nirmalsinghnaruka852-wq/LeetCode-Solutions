
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

        vi arr = merge(0, n - 1, nums);

        int ans = INT_MAX;

        ans = min(ans, arr[n - 1] - arr[2]);
        ans = min(ans, arr[n - 2] - arr[1]);
        ans = min(ans, arr[n - 3] - arr[0]);

        return ans;
    }
};
