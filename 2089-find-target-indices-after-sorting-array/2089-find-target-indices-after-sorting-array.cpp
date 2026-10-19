using vi = vector<int>;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vi ans ; 
        for(int index =0 ; index < nums.size() ; index++){
            if(nums[index] == target) ans.push_back(index); 
        }
        return ans ; 
    }
}; 