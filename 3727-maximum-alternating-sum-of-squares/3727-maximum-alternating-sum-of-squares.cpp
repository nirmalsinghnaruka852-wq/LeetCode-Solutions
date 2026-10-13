class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ;
        for(int index =0 ; index < n ; index++ ){
            nums[index] = nums[index] * nums[index];
        }
        sort(nums.begin() , nums.end() , [](int a , int b ){
          return a > b ; 
        });
        int i =0 ;
    
        int j = n- 1 ; 
        long long sum = 0 ; 
        while(i < j ){
         sum += nums[i++];
         sum -= nums[j--];
        }
        if(i == j ) sum += nums[i];
        return sum  ; 
    }
};
//  how we can solve this question let say ;
//  the first one what dose the question say ? ;
// convert the array into the  the squre array which cost is the O(n);
//  then sort it desnding order which cost would be O(n logn );
//  convert the two poitner appraoch which is the good then one ;

