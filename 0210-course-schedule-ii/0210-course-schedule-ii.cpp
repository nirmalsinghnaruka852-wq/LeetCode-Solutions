class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>degree(numCourses, 0);
        for(auto edge : prerequisites){
          // u ->v;
          int u = edge[0];
          int v = edge[1];
          adj[v].push_back(u);
          degree[u]++;
        }
        queue<int>q;
        for(int index = 0 ; index < numCourses ; index++){
          if(degree[index]== 0 ){
            q.push(index);
          }
        }
        vector<int>ans;
        while(!q.empty()){
         int node = q.front();
         q.pop();
         ans.push_back(node);
         for(int nebghior : adj[node]){
             degree[nebghior]--;
             if(degree[nebghior] == 0 )
             q.push(nebghior);
                      }
        }
        for(int deg : degree){
          if(deg != 0) return {};
        }
        return ans ;
    }
};
// return  the topological sort ;
// if there is cycle ther return  {};
