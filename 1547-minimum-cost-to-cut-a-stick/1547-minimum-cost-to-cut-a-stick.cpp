using vi =vector<int>;
using vvi =vector<vi>;
class Solution {
public:
    vvi dp ;  
    // (l -> 0 , r -> n  , stick1 -> 0 , stickr -> n , cuts );
   int solve(int l , int r , int stickl  , int stickr  , vi& cuts){
    if(l >= r ) return 0 ; 
    else if(dp[l][r] != -1 ) return dp[l][r];
    int minOne = INT_MAX ; 
    for(int point = l ; point < r ; point++ ){
        int cost = stickr - stickl;
        int performCut = solve(l , point , stickl , cuts[point], cuts) + solve(point+1 , r , cuts[point] , stickr, cuts );
        minOne = min(minOne , cost + performCut  ); 
    } 
    return dp[l][r] = minOne ; 
   }
    int minCost(int n, vector<int>& cuts) {
      sort(cuts.begin() , cuts.end() );        
     int m = cuts.size() ;
     dp.resize( m+1 , vi( m+1 , -1 )) ;
      return solve(0 ,  m  ,  0 ,  n , cuts );
    }
};

