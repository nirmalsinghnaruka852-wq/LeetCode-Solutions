using vi = vector<int>;
using vvi = vector<vector<int>>;
class Solution {
public:
  vi p ;
  vvi dp ;
   // flag = 1 -> we don't have stock, so we can BUY
    // flag = 0 -> we have stock, so we can SELL
   int MaxiumProfitCalculation(int currentIndex , int flag ){
    if(currentIndex >= p.size() ) return 0 ; 
    if(dp[currentIndex][flag] != -1 ) return dp[currentIndex][flag] ; 
     if(flag){
        // we can  thinges like buy this one and do nothing like that ;
        int buy = -p[currentIndex] + MaxiumProfitCalculation(currentIndex+1 , 0 );
        int doNothing =  MaxiumProfitCalculation(currentIndex+1 , flag);
        return dp[currentIndex][flag] = max(buy , doNothing);

     }else{
        //  we can sell this one day and do nothing ;
        int sell = p[currentIndex] + MaxiumProfitCalculation(currentIndex+1 , 1);
        int doNothing =  MaxiumProfitCalculation(currentIndex+1 , flag);
        return dp[currentIndex][flag] = max(sell , doNothing);
     }

   }
    int maxProfit(vector<int>& prices) {
        p = prices;
        int n = prices.size() ;
        dp.resize(n ,vi(2 , -1 ));
        return MaxiumProfitCalculation(0 , 1);
    }
};