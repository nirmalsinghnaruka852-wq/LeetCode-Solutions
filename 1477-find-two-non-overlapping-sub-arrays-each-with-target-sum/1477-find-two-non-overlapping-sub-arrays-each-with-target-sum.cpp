using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vvi dp;
    vi prefix;
    int n;
    int solve(int currentIndex, int rem, int target) {
        if (rem < 0)
            return 0;
        else if (currentIndex >= n  )
            return INT_MAX;
        else if (dp[currentIndex][rem] != -1)
            return dp[currentIndex][rem];

        //  skip ;
        int ans = solve(currentIndex + 1, rem, target);

        // binary search on prefix Array ;
        int left = currentIndex;
        int right = n ;
        int nextIndex = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = prefix[mid] - prefix[currentIndex];
            if (result == target) {
                nextIndex = mid;
                break;
            } else if (result > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (nextIndex != -1) {
            //    here we can perfrom pervation like the solve return
            //    INT_MAX then ;
            cout<< currentIndex << " "<< nextIndex << endl; 
            int ans2 = solve(nextIndex , rem - 1, target);
            ans2 = ans2 == INT_MAX ? ans2 : (nextIndex - currentIndex) + ans2;
          ans = min(ans , ans2 );
        }
        return dp[currentIndex][rem] = ans;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        n = arr.size();
        int m = 2;
        dp.resize(n, vi(m, -1));
        prefix.resize(n + 1);
        int sum = 0;
        for (int index = 0; index < n + 1; index++) {
            prefix[index] = sum;
            if (index == n)
                continue;
            else
                sum += arr[index];
            // cout << prefix[index] << " ";/
        }
        int ans = solve(0, 1, target);
        return ans == INT_MAX ? -1 : ans ;
    }
};

//  in this question u have to return the 2 nonOverlaping sub-array's length
//  which sum are equal to the target sum ; and also if there are multiple
//  subarray then u have to return minone length ;

//  let we thing how i can solve this question ;
