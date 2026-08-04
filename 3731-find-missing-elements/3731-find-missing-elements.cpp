class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
     int Min = INT_MAX;
     int Max = INT_MIN;
     for(int num : nums){
      Min = min(Min , num);
      Max = max(Max , num);
     }
     set<int>st(nums.begin() , nums.end() );
     vector<int>ans ; 
     for(int element = Min + 1 ; element < Max ; element++){
      if(!st.count(element)) ans.push_back(element);
     }
     return ans ;   
    }
};