using vi =  vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int  n ;
    int m;
    vvi dp ;
    int maxiumUnCrossedConnection(int i  , int j , vi arr1 , vi arr2 ){
      if(i >= n || j >= m) return 0 ;
      if(dp[i][j] != -1) return dp[i][j];
      if(arr1[i] == arr2[j] ) return dp[i][j] = 1+ maxiumUnCrossedConnection(i+1 , j+1  , arr1 ,arr2);
      else return dp[i][j]= max(maxiumUnCrossedConnection(i+1 , j ,arr1, arr2),
        maxiumUnCrossedConnection(i , j+1 , arr1 ,arr2)) ;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size() ;
        m = nums2.size();
        dp.resize(n, vi(m , -1));
        return maxiumUnCrossedConnection(0 , 0 , nums1 , nums2);
    }
};