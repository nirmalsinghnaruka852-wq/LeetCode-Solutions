class Solution {
public:
   char colorToChild(char parentColor = 'W'){
    return parentColor == 'R' ? 'W' : 'R';
   }
    bool dfs(int index , char color , vector<vector<int>>&adj , vector<bool>&visited , vector<char>&colourMatrix){
      if(visited[index]) return colourMatrix[index] != color ; 
      visited[index] = true ;
      colourMatrix[index] = color ;
      bool ans = false ; 
      for(int edge : adj[index]){
        ans = ans ||  dfs(edge , colorToChild(color), adj ,visited , colourMatrix );
      } 
      return ans ; 
    }
    bool isBipartite(vector<vector<int>>& graph){
      int n = graph.size() ;
        vector<bool>visited(n , false );
        vector<char>colourMatrix(n , ' ');

        bool ans = true  ;
        for(int index = 0 ; index < n ; index++ ){
          if(!visited[index])
         ans = ans &&  ! dfs(index, colorToChild() , graph , visited , colourMatrix);
        }    
        return ans ; 
    }
};