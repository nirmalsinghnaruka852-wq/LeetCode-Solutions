class Solution {
public:
   bool isHave(int index , vector<vector<int>>& adj , vector<bool>&visited , int destination ){
    if(visited[index] ) return false ;
    if(index == destination )return true ;
    visited[index] = true ;
    bool ans = false ;
    for(int edge : adj[index]){
      ans = ans||  isHave(edge , adj , visited , destination );

    }
    return ans ; 
   }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto edge : edges){

          adj[edge[0]].push_back(edge[1]) ;
          adj[edge[1]].push_back(edge[0]);
        } 
        vector<bool>visited(n , false );
       return isHave(source , adj , visited , destination );

    }
};
//  the first task is convert the edge list into the adj list ;
//  now we have the adj list 