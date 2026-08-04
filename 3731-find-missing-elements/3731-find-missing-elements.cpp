class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums){
      int n = 101 ;
      vector<int>count(n , 0);
     int Min = INT_MAX;
     int Max = INT_MIN;
     for(int num : nums){
      count[num] = 1 ; 
      Min = min(Min , num);
      Max = max(Max , num);
     }
    //  set<int>st(nums.begin() , nums.end() );
     vector<int>ans ; 
     for(int element = Min + 1 ; element < Max ; element++){
      if(count[element] == 0 ) ans.push_back(element);
     }
     return ans ;   
    }
};
//  optimaztion ; 