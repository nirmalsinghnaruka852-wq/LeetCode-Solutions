class Solution {
public:
  double max(double   a , double b){
    if( a > b) return a ;
    else return b ; 
  }
    double findMaxAverage(vector<int>& nums, int k) {
      int i = 0 ;
      int j = 0 ;
      int sum = 0 ;
      while(j < nums.size() && j < k ){
        sum += nums[j++];
      }
      double Max = (double) sum /k;
      for(int index = k ; index < nums.size() ; index++){
        sum -= nums[i++];
        sum+= nums[index];
        Max = max(Max ,  (double)sum /k);
      }
      return Max ; 
    }
};
//  int i = 0 ;
//  int j++ unilt it reach the k ;
//  sum those values ;
//  check the avarge and push it ;
//  loop from k to n ;
// remove the first elemnt ;
// add new element check the new Average until we reach the  last element ;
//  and just return the maxOne ; 