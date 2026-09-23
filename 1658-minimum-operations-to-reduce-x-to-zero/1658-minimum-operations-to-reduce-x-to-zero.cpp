class Solution {
public:
    int minOperations(vector<int>& nums, int x){
        int total = std::accumulate(nums.begin() , nums.end() , 0);
        int targetSum = total - x ;
        int i = 0 ;
        int currentWindowSum = 0 ;
        int maxLength = -1 ; 
        for(int index = 0 ; index < nums.size(); index++){
            currentWindowSum += nums[index];
            while(currentWindowSum > targetSum && i <= index ){
                currentWindowSum -= nums[i++];
            }
            if(currentWindowSum == targetSum){
                maxLength = max(maxLength , index - i + 1 );
            }
        } 
        if(maxLength == -1 ) return maxLength ; 
        return nums.size() - maxLength ; 
    }
};


//  find the maxium length subarray which have the sum = total - k ;
//  return the totallength - subarrylenth ;   

//  if the sum > = total - k ;
//  then what we can do like reduse it ;
