class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            __int128 product = 1;
            long long lcm = 1;
            long long g = 0;

            for (int j = i; j < n; j++) {
                long long x = nums[j];

                g = gcd(g, x);

                long long newLCM = (lcm / gcd(lcm, x)) * x;

                // Check before multiplication
                if (product > ((__int128)LLONG_MAX * LLONG_MAX) / x) {
                    break;
                }

                product *= x;
                lcm = newLCM;

                __int128 expected = (__int128)lcm * g;

                if (product == expected) {
                    ans = max(ans, j - i + 1);
                }

                if (product > expected) {
                    break;
                }
            }
        }

        return ans;
    }
};