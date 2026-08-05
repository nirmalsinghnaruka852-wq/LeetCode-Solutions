using vi = vector<int>;
class Solution {
public:
  vi dp ; 
  int lastIndex  ; 
   int dfs(int index , vi& cost ){
    if(index >= lastIndex )  return index == lastIndex ? cost[lastIndex] : 0;
    if(dp[index]  != -1 ) return dp[index];
    // return cost[index] + min(dfs(index +1 , cost) , dfs(index+2 , cost));
    return dp[index] = cost[index] + min(dfs(index +1 , cost) , dfs(index+2 , cost));

   }
    int minCostClimbingStairs(vector<int>& cost){
       lastIndex = cost.size() -1 ;
       int n  = cost.size() ;  
       dp.resize(n , -1 );
       return min(dfs(0 ,cost ) , dfs(1 ,cost)); 
    }
};

//  here  can r epsent that in term of the index yes or no ;
// yes ;  