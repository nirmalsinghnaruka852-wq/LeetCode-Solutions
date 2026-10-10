
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();

        map<int, long long> mp;
        long long totalDiff = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            mp[d]++;
            totalDiff += d;
        }

        long long k = 1LL * k1 + k2;

    
        if (k >= totalDiff) return 0;

        vector<pair<int, long long>> ans;

        for (auto const& [d, freq] : mp) {
            ans.push_back({d, freq});
        }

        reverse(ans.begin(), ans.end());

        int m = ans.size();

        for (int i = 0; i < m; i++) {
            long long current = ans[i].first;
            long long freq = ans[i].second;

            long long nextDiff =
                (i + 1 < m) ? ans[i + 1].first : 0;

            long long operations =
                (current - nextDiff) * freq;

            if (k >= operations) {
            
                k -= operations;

                if (i + 1 < m) {
                    ans[i + 1].second += freq;
                }
            } else {
               
                long long reduction = k / freq;
                long long remainder = k % freq;

                long long finalDiff = current - reduction;

                long long result =
                    (freq - remainder) * finalDiff * finalDiff
                    + remainder * (finalDiff - 1)
                                  * (finalDiff - 1);

               
                for (int j = i + 1; j < m; j++) {
                    long long d = ans[j].first;
                    result += ans[j].second * d * d;
                }

                return result;
            }
        }

        return 0;
    }
};
