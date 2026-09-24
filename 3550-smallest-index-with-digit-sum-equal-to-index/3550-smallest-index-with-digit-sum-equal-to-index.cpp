class Solution {
public:
    int smallestIndex(vector<int>& nums) {

      int n = nums.size() ;
    //   int result = 0 ; 
    int smallestElement = -1 ; 
      for(int index = 0 ; index < n ; index++){
        int sum = 0 ;
        int currentNumber = nums[index] ;
        while(currentNumber > 0  ){
            // sum *=  10 ;
            sum +=  currentNumber % 10 ;
            currentNumber/= 10 ; 
        }
        cout << sum << "-? " << index << endl; 
        if(sum == index) return index ;  
      }

     return -1  ; 
    }
};