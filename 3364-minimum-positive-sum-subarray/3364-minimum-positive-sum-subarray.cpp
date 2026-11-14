
// Code
// Testcase
// Testcase
// Test Result
// 3364. Minimum Positive Sum Subarray 
// Easy - 825
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.

// Return the minimum sum of such a subarray. If no such subarray exists, return -1.

// A subarray is a contiguous non-empty sequence of elements within an array.

 


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
     int ans = INT_MAX ;
     int n = nums.size(); 
     for(int start = 0 ; start < n ;start++){
        int sum = 0 ;
        for(int end = start ;end < n ; end++ ){
            sum += nums[end];
            int size = (end - start) + 1 ;
            if(size > r )break ;
            else if(l <= size && size <= r )
            if(sum <= 0 ) continue ;
            else ans = min(ans , sum );
        }  
     }
     return (ans == INT_MAX ) ? -1 : ans  ;   
    }
};
