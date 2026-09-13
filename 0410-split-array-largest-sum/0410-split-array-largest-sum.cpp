using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int n;
    vvi dp;
    int dfs(int currentIndex, int remainingPieces, vi& nums) {

        if (currentIndex == n)
            return remainingPieces == 0 ? 0 : INT_MAX;

        if (remainingPieces == 0)
            return INT_MAX;

        if (dp[currentIndex][remainingPieces] != -1)
            return dp[currentIndex][remainingPieces];

        int currentSum = 0;
        int ans = INT_MAX;

        for (int index = currentIndex; index < n; index++) {

            currentSum += nums[index];

            int remainingAnswer = dfs(index + 1, remainingPieces - 1, nums);

            ans = min(ans, max(currentSum, remainingAnswer));
        }

        return dp[currentIndex][remainingPieces] = ans;
    }
    int splitArray(vector<int>& nums, int k){
        n = nums.size() ;
        dp.resize(n , vi(k+1 , -1));
        return dfs(0 , k , nums );
    }
};

//  we have to convert the array  into  the non  subarry to
// the  largest Sum of any subarray is minimized ok ;

//  the question we have to split the array in the k subarray ;

//  we have to return the maxium sum ;
// jitne bhi subarray hai unka maxium and the then return minOne  return minOne
// ;