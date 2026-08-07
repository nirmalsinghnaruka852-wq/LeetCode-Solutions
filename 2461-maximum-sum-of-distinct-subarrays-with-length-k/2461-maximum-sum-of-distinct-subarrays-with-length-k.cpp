class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // suarray length should be equal to the k ; 
        //  and also make sure there all element are distent ;
        //  them take that subarray as a vaild take that array sum ;
        set<int>st ;
        int i = 0 ; 
        int j = 0 ;
        long long sum = 0; 
        int m = nums.size() ; 
        while(j < m && j < k){
          while(!st.empty() && st.count(nums[j])){
            st.erase(nums[i]);
            
            
            sum -= nums[i];
          i++ ;
          }
          sum+=nums[j];
          st.insert(nums[j]);
          j++;
        }
        long long Max = 0 ; 
        if(st.size() == k ) Max = sum ;
       for(int index  = j ; index < m ; index++){
        if(index >= i + k ){ st.erase(nums[i]);
        sum -= nums[i] ;
        i++ ;
        }
         while(!st.empty() && st.count(nums[index])){
            st.erase(nums[i]);
            sum -= nums[i];
            i++ ;
          }
          sum += nums[index];
          st.insert(nums[index]);
          if(st.size() == k ) Max = max(Max , sum );
       }
       return Max; 

    }
};