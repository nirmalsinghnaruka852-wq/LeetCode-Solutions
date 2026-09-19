class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0 ;
        int j = 0 ;
        int zero = 0 ;
        int maxSize = INT_MIN ;
        for(int index = 0  ; index < nums.size() ; index++ ){
            if(nums[index]== 0 ) zero++ ;
            j++ ;
            while(zero > k ){
                if(nums[i] == 0 ) zero-- ;
                i++ ; 
            }
           maxSize = max(maxSize , j - i );
        }
    return maxSize ; 
    }
};