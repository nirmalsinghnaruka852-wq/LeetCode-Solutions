//  the same thinge but whenever we sell then that then we have to add the profit ; 
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
class Solution {
public:
    vvvi dp;
    int n;
    vi price ; 
    // int fees ; 
    int solve(int i = 0  , int flag = 1 , int remaningTransation = 2  ) {
        if (i >= n || remaningTransation == 0 )
            return 0;
        if (dp[i][flag][remaningTransation] != -1)
            return dp[i][flag][remaningTransation];
        int MaxOne = INT_MIN;
        if (flag == 1) {
            // mean we have liberty to buy that stock and do nothing ;
            int buy = -price[i] + solve(i + 1, 0 , remaningTransation);
            int do_nothing = solve(i + 1, flag , remaningTransation );
            MaxOne = max(buy, do_nothing);
        } else {
            //  mean have to sell or do nothing ;
            int sell = price[i] + solve(i + 1, 1, remaningTransation -1 );
            int do_nothing = solve(i + 1, flag, remaningTransation);
            MaxOne = max(sell, do_nothing);
        }
        return dp[i][flag][remaningTransation] = MaxOne;
    }
    int maxProfit(vector<int>& prices){
        n = prices.size();
        dp.resize(n, vvi(2, vi(3 , -1)));
        price = prices ;
        // fees = fee ; 
        return solve();
    }
};

//  we can buy multiple stock , but at a certien point we only have one stock ;
//  after selling we can't buy stock next day ;
//  what is your intition ok firstly we have to discuse about it then we will
//  move futher and also that is feasible or not for the current siwtecthion ;

