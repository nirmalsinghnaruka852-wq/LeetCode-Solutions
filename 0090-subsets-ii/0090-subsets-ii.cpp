using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vvi result ;
    vi path ; 

     int nextVaildindex(int index , vi nums){
        int  j = index + 1 ;
        while(j < nums.size()){
            if(nums[j] != nums[index]) return j  ; 
            j++;
        }
        return nums.size() ; 
     }
    void solve(int currentIndex , vi& nums){
        if(currentIndex >= nums.size() ){  result.push_back(path );  return ;}
        //   pick ;
        path.push_back(nums[currentIndex]);
        solve(currentIndex +1 , nums);
        path.pop_back();
        solve(nextVaildindex(currentIndex , nums ) , nums);
        return ; 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end() );
        solve(0 , nums);
      return result ;    
    }
};


