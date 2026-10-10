using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
     vvi ans ; 
     int n = costs.size() /2 ; 
     for(int index =0 ; index < n* 2 ; index++){
        int differnce = costs[index][0] -costs[index][1];
        ans.push_back({costs[index][0] , costs[index][1] , differnce});
     }
       sort(ans.begin() , ans.end() , [](auto a , auto b){
         return a[2] < b[2];
       });

       int ans1 = 0 ;
      for(int index =0 ; index < n *2 ; index++){
        // cout << ans[index][2]<< endl ;
        if(index < n ) ans1 += ans[index][0];
        else ans1 += ans[index][1];
      }
      return ans1 ;
    }
};
// then the starting n goes to the there and tother gose there like that 
