class Solution {
public:
   bool dfs(int node , int curr , vector<int>& colour , vector<vector<int>>&adj){
    if(colour[node] != -1 ) return colour[node] == curr ;
     colour[node] = curr ;
    bool ans = true ;
    for(int nebhior : adj[node])
       ans = ans && dfs(nebhior , curr == 0 ? 1 : 0 , colour , adj );
    return ans ; 
   }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes){
     vector<vector<int>>adjanecyList(n+1);
     vector<int>color(n+1 , -1);
     for(vector<int>& edge : dislikes){
      int u = edge[0];
      int v = edge[1];
      adjanecyList[u].push_back(v);
      adjanecyList[v].push_back(u);
     }    
     for(int index = 1 ; index < n+1 ; index++){
      if(color[index] != -1 ) continue ;
      else if(!dfs(index , 0 , color, adjanecyList)) return false ;
     }
     return true ;
    }
};  