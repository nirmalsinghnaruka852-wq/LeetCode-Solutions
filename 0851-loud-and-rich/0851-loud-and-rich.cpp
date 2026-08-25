using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
     void dfs(int currentIndex , vvi& adjList , vi& quiet , vi&ans){
     for(int child : adjList[currentIndex]){
      ans[child] = min(quiet[ans[child]] , quiet[ans[currentIndex]]) == quiet[ans[child]] ?
       ans[child] : ans[currentIndex]; 
     }
    return  ; 

    }


    vector<int> loudAndRich(vector<vector<int>>& edgeList, vector<int>& quiet) {
        //  convert the edge_List into the adjlist ;
        int n = quiet.size() ;
        vi inDegree(n , 0 );
        vi ans(n );
        vvi adj(n);
        //  the given graph is the directed graph ; 
        for(int index = 0 ; index < n ; index++){
          ans[index] = index ;
        }
        for(vi& edge : edgeList){
          int u = edge[0];
          int v = edge[1];
          adj[u].push_back(v);
          inDegree[v]++ ;
        }
        queue<int>q ;
        for(int index = 0 ; index < n ; index++ ){
          if(inDegree[index] == 0 ) q.push(index);
        }
        vi topoSort ;
         while(!q.empty()){
          int node = q.front() ;
          topoSort.push_back(node);
          q.pop();
          for(int neighbor : adj[node]){
            inDegree[neighbor]-- ;
            if(inDegree[neighbor]== 0 ) q.push(neighbor);
          }
         }
      for(int element : topoSort){
        dfs(element ,adj ,quiet , ans );
      }
        return ans ;
    }
};
 