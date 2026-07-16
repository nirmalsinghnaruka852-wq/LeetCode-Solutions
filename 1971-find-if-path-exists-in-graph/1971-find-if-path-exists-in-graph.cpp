class Solution {
public:
   bool isHave(int index , vector<vector<int>>& adj , vector<bool>&visited , int destination ){
    queue<int>q ;
    q.push(index);
    visited[index]= true ;
    while(!q.empty()){
      auto node = q.front();
      q.pop() ;
        if(node  == destination ) return true ;  
      for(auto edge : adj[node]){
        if(visited[edge]) continue ;
         q.push(edge);
         visited[edge] = true ; 
      
      }
    } 
    return false ;
    }
 
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      if(source == destination ) return true ;
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