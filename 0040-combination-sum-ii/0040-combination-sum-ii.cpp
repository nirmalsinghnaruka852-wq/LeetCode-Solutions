using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
     vi ans ;
     vvi result ; 
    void backTracking(int index, vector<int>& candidates, int target) {

        if (target == 0) {
            result.push_back(ans);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            
            if (candidates[i] > target) break;

            ans.push_back(candidates[i]);

            backTracking(i + 1, candidates, target - candidates[i]);

            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        

        sort(candidates.begin(), candidates.end()); 

        backTracking(0, candidates, target);

        return result;
    }
};