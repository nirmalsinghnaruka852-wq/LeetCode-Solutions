
using vi = vector<int>;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int minPrice = INT_MAX;

        vi dp(budget + 1, 0);

        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int units = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    units++;
                }
            }


            for (int b = budget; b >= price; b--) {
                dp[b] = max(
                    dp[b],
                    dp[b - price] + units
                );
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            int extra = (budget - b) / minPrice;

            ans = max(ans, dp[b] + extra);
        }

        return ans;
    }
};
