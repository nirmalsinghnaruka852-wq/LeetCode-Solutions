using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vvi dp;
    int n;
    vi price ; 
    int solve(int i = 0  , int flag = 1 ) {
        if (i >= n)
            return 0;
        if (dp[i][flag] != -1)
            return dp[i][flag];
        int MaxOne = INT_MIN;
        if (flag == 1) {
            // mean we have liberty to buy that stock and do nothing ;
            int buy = -price[i] + solve(i + 1, 0);
            int do_nothing = solve(i + 1, flag);
            MaxOne = max(buy, do_nothing);
        } else {
            //  mean have to sell or do nothing ;
            int sell = price[i] + solve(i + 2, 1);
            int do_nothing = solve(i + 1, flag);
            MaxOne = max(sell, do_nothing);
        }
        return dp[i][flag] = MaxOne;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n, vi(2, -1));
        price = prices ;
        return solve();
    }
};

//  we can buy multiple stock , but at a certien point we only have one stock ;
//  after selling we can't buy stock next day ;
//  what is your intition ok firstly we have to discuse about it then we will
//  move futher and also that is feasible or not for the current siwtecthion ;
