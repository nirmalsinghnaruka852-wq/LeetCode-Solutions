using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int , int >;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
      int n = graph.size() ;
      vvb dp(n , vector<bool>((1 << n ) , false ));
      int size  = 0 ;
      int level = 0 ; 
      int fullMask = (1 << n ) -1 ;  
      //  {first : node , second : mask };
      queue<pii>q ;
      for(int u = 0 ; u < n ; u++ ){
        q.push(make_pair(u , (1 << u)));
      }
      size  = q.size() ;
      while(!q.empty()){
        pii path = q.front() ;
        q.pop() ;
        size-- ;
        if(path.second == fullMask  ) return level ;
        for(int neighbor : graph[path.first]){
          int newBitMask = path.second | (1 << neighbor)   ;
          if(dp[neighbor][newBitMask]) continue ;
          q.push(make_pair(neighbor , newBitMask));
          dp[neighbor][newBitMask] = true ;
        }
        if(size == 0 ){
          size = q.size() ;
          level++ ; 
        }
      }
     return 0 ;    
    }
};