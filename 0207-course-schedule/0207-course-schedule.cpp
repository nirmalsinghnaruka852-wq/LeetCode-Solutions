class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        vector<int>degree(n , 0);
        for(auto edge : p){
          adj[edge[0]].push_back(edge[1]);
         degree[edge[1]]++ ;
        }
        queue<int>q ;
        for(int index = 0 ; index  < n ; index++ ){
          if(degree[index] == 0 ) q.push(index);
        }
        while(!q.empty()){
          int node = q.front() ;
          q.pop() ;
          for(int edge : adj[node]){
            degree[edge]--;
            if(degree[edge] == 0){
              q.push(edge);
            }
          }
        }
     for(int index : degree){
      if(index != 0) return false ;
     }
     return true ; 
    }
};
// check there is cycle or not 
// if there is cycle the return false ;
//  and if there is no cycle then return true ;

//  first task is convert the edge list into the adj list 