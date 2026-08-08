using vi = vector<int>;

class Solution {
public:
   vi dp ; 
   int dfs(int startPoint  , int k ,vi& arr ){
    if(startPoint >= arr.size() ) return 0 ;
    if(dp[startPoint] != -1) return dp[startPoint];
    int limit = startPoint + k ;
    int Max = INT_MIN ; 
    int ans = INT_MIN; 
     for(int index = startPoint ; index < limit && index < arr.size() ; index++){
     Max =  max(Max, arr[index]);
     ans = max(ans,
          Max * (index - startPoint + 1) +
          dfs(index + 1, k, arr));
     }
    return  dp[startPoint] = ans ;
   }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      dp.resize( arr.size() , -1 );
       return dfs(0 , k , arr); 
    }
};