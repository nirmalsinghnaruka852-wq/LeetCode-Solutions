using vi  = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;


class Solution {
public:

    vvvi dp;
    vi groups;
    vi  profits;

    static const int MOD = 1e9 + 7;

    int generateTotalValidNumberOfSchemes(
        int currentIndex,
        int remainingPerson,
        int currentProfit,
        int minProfit
    ) {

        if (currentIndex >= groups.size()) {
            return currentProfit >= minProfit ? 1 : 0;
        }

        if (dp[currentIndex][remainingPerson][currentProfit] != -1)
            return dp[currentIndex][remainingPerson][currentProfit];

   
        int not_take = generateTotalValidNumberOfSchemes(
            currentIndex + 1,
            remainingPerson,
            currentProfit,
            minProfit
        );

        int take = 0;

        if (groups[currentIndex] <= remainingPerson) {

            int newProfit = min(
                minProfit,
                currentProfit + profits[currentIndex]
            );

            take = generateTotalValidNumberOfSchemes(
                currentIndex + 1,
                remainingPerson - groups[currentIndex],
                newProfit,
                minProfit
            );
        }

        return dp[currentIndex][remainingPerson][currentProfit] =
            (take + not_take) % MOD;
    }

    int profitableSchemes(
        int n,
        int minProfit,
        vector<int>& group,
        vector<int>& profit
    ) {

        groups = group;
        profits = profit;

        int crimes = group.size();

        dp.resize(
            crimes,
            vvi(
                n + 1,
                vector<int>(minProfit + 1, -1)
            )
        );

        return generateTotalValidNumberOfSchemes(
            0,
            n,
            0,
            minProfit
        );
    }
};