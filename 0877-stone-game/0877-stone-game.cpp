class Solution {
public:
   vector<vector<int>>dp; 
    int MinMax(int left , int right  , vector<int>& piles){
      if(left == right ) return piles[left];
      if(dp[left][right ] != -1 ) return dp[left][right];
      int leftTake = piles[left]  -  MinMax(left + 1 , right  , piles);
      int rightTake = piles[right] - MinMax(left , right -1 , piles);
      return dp[left][right]= max(leftTake , rightTake);
    }
    bool stoneGame(vector<int>& piles) {
      int n = piles.size() ;
      dp.resize(n , vector<int>(n , -1 ));

        return MinMax(0 , piles.size()-1  , piles) >= 0 ;
    }
};