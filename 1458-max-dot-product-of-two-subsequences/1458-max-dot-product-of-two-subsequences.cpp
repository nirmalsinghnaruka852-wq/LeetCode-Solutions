using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int n;
    int m ; 
    vvi dp;
    int maxumDotProduectGenerate(int i, int j, vi& n1, vi& n2) {
        if (i >= n || j >= m)
            return INT_MIN ;
        else if (dp[i][j] != INT_MIN)
            return dp[i][j];
        // ma/xOne = INT_MIN ;
        int maxOne =
            n1[i] * n2[j] + max(0, maxumDotProduectGenerate(i + 1, j + 1, n1, n2)) ;
        maxOne = max(maxOne, 
                     max(maxumDotProduectGenerate(i + 1, j, n1, n2),
                         maxumDotProduectGenerate(i, j + 1, n1, n2)));
        return dp[i][j] = maxOne;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
         n = nums1.size();
         m = nums2.size(); 
        dp.resize(n, vi(m , INT_MIN));
        // int minOne = INT_MIN ;
        // int minTwo = INT_MIN ;
        // for(int ele : nums1){
        //   minOne = max(minOne , )
        // }
        return maxumDotProduectGenerate(0, 0, nums1, nums2);
    }
};