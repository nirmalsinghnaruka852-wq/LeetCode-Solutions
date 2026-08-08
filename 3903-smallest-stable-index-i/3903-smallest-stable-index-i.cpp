class Solution {
public:
  int find(int index , vector<int>& nextSmaller ){
    if(index == nextSmaller[index] ) return index ;
    return nextSmaller[index]  = find(nextSmaller[index], nextSmaller);
  }
    int firstStableIndex(vector<int>& nums, int k) {
      int n = nums.size();
     vector<int>nextSmaller(n);
      for(int index = 0 ; index < n ; index++){
        nextSmaller[index] = index ; 
      }
      stack<int>st ;
      for(int index = 0 ; index < n ; index++){
        int currentElement = nums[index];
        while(st.size()>= 1 && currentElement < nums[st.top()]){
          nextSmaller[st.top()] = index ;
          st.pop(); 
        }
        st.push(index); 
      }
      for(int index = 0 ; index < n ; index++){
        cout << index << "->" << nextSmaller[index] << endl;
      }
      int Max = INT_MIN ;
      int MinOne = INT_MAX;
      for(int index = 0 ; index < n ; index++){
        Max = max(Max , nums[index]);
        int i = index ; 
        
        
        // while(i != nextSmaller[i])  i = nextSmaller[i];
        int SmallestNUmber = nums[find(i , nextSmaller)];
        int differ = Max - SmallestNUmber ;
         if(differ <= k ) return index ;
      }
       return -1 ; 
    }
};

//  