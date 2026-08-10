class Solution {
public:
     vector<long long>dp ; 
     long long maximumPoints(int curr , int size , vector<vector<int>>& questions){
      if(curr >= size) return 0 ;
      if(dp[curr] != -1 ) return dp[curr];
      long long take = 1LL *questions[curr][0] + maximumPoints(curr+questions[curr][1] +1 , size ,  questions );
      long long skip = 1LL * maximumPoints(curr +1 , size ,  questions );
      return dp[curr] =1LL *  max(take , skip);
     }
    long long mostPoints(vector<vector<int>>& questions) {
      int n = questions.size() ;
      dp.resize(n , -1 );
      return maximumPoints(0 ,n ,questions);
        
    }
};