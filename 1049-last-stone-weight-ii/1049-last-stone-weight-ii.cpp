class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int total = 0;

        for (int x : stones)
            total += x;

        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones) {

            for (int sum = target; sum >= stone; sum--) {

                dp[sum] = dp[sum] || dp[sum - stone];
            }
        }

        int best = 0;

        for (int sum = target; sum >= 0; sum--) {

            if (dp[sum]) {
                best = sum;
                break;
            }
        }

        return total - 2 * best;
    }
};

//  at a point we can pick a element and we can do the sames we want the at the value which is nearest to 0 and which is also greater then the 0 ;
//  like nearest to 0 and also greater then the 0 ;
//  at the point we take the number as add or subtracht like taht 
