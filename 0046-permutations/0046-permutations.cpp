using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
class Solution {
public:
     vi permutation;
     vvi permutations;
     vb used ; 
     int n ; 
     void generateAllPossiblePermutations(vi& nums){
        if(permutation.size() == nums.size() ){
          permutations.push_back(permutation);
          return ; 
        }
        for(int index =0 ; index < n; index++ ){
          if(used[index]) continue ;
          used[index] = true  ;
          permutation.push_back(nums[index]);
          generateAllPossiblePermutations(nums);
          permutation.pop_back() ; 
          used[index] = false ; 
        }
        return ; 
     }
    vvi  permute(vi& nums) {
      n = nums.size();
      used.resize(n , false );
       generateAllPossiblePermutations(nums);
    return permutations;        
    }
};