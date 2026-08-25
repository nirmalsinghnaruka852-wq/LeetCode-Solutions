class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k){
      int  n = nums.size() ;
      map<int , int >mp ; 
      int count = 0 ; 
      int totalOdd = 0 ; 
      for(int index = 0 ; index < n ; index++ ){
        if(nums[index] % 2 == 1 ) totalOdd++ ;
        if(totalOdd == k ) count++ ;
        int require = totalOdd -  k ;
        if(mp.count(require)) count+= mp[require] ;
         mp[totalOdd]++  ;
      }
      return count  ; 
        
    }
};