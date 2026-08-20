using vi = vector<int>;
using vii = vector<vi>;
class Solution {
public:
  vii result ;
     void dfs(int anstor , int index , vii& adj ){
      for(int edge : adj[index]){
        if(result[edge].size() >= 1 && result[edge][result[edge].size()-1] == anstor ) continue ;
        else result[edge].push_back(anstor);
        dfs(anstor , edge , adj);
      }
      return ;
     }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
     result.resize(n);
     vii adj(n);
     for(vi& edge : edges ){
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
     }
     for(int index = 0 ; index < n ; index++ ){
      cout << index << "->";
      for(int edge : adj[index]){
        cout<< edge <<" ";
      }
      cout<< endl ;
     } 
     for(int index = 0 ; index < n ; index++){
      dfs(index , index , adj );
     }
     return result ;   
    }
};


//  in the question there is givin the number of the node ;
//  ans also the edge list ;
//  and the graph is the dag (directed Acyclic graph);



//  and the algorthm is traver the 
//  take the each node as a starting point and also which node we can traverse for the curennt 
//  put that into the parentnode inot that node index ;
//  and also there is dag then we don't need to use the visited ;



//  algorith is that '
//   1.start ;
//  create the result ;
//  loop form 0 to n-1 ;
//        - take the current node as a anstore 
//         do dfs on that 
//          put the anstore to the current node while we are traverseing ;
//  return result ;   