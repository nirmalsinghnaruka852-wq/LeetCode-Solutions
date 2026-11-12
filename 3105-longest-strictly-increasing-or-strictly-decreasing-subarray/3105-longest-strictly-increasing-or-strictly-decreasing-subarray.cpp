using vi = vector<int>;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    //  algorigthm ;
    // 1. start ;
    //  make two dp arrray like incressing and the decressing ok ;
    //  then we start the traversing the array from right to left ;
    //  the dp trastaion would be like in the incressing then we check the prevelement  that is incressing then add those else do nothing ;
    // and in the decressing we will same as well the trasation will be oppsite 
    //   that  ok ;
    int n = nums.size() ;
    int maxOne = 1 ; 
     int lastElementInc = 1 ;
     int lastElemntDec = 1  ; 
    for(int index = n-2 ; index >= 0 ; index--){
          int currentInc= 1 + ((nums[index] < nums[index+1]) ?  lastElementInc : 0 ); 
         int currentDec = 1 + ((nums[index] > nums[index+1]) ?  lastElemntDec : 0 ); 
         lastElementInc = currentInc ;
         lastElemntDec  = currentDec ; 
      maxOne = max(lastElementInc , max(lastElemntDec , maxOne));
    }
    return maxOne ; 
    }
};


//  we just have to return the longest incressing or the longest decressing ; 


// brute force apporach in which we will calculate the each possblie subarray ;

// we also can do like the dp  here which cost will O(n); 

//  there is one important constrains which is the  u can't be skip any element ;
//  sub-array mean a that is part of array and also that should be continues ; like that 

