using vi = vector<int>;
using Matrix = vector<vector<int>>;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
      int n = graph.size() ;
        vi outDegree(n , 0 );
          for(int index = 0 ; index < n ; index++){
          outDegree[index] = graph[index].size() ;
        }
        Matrix reverseGraph(n);
        for(int index = 0 ; index < n ; index++){
          for(int edge : graph[index]){
            reverseGraph[edge].push_back(index); 
          }
        }
      for(int index = 0 ; index < n ; index++){
        cout << index << "-> " ;
        for(int edge : reverseGraph[index]){
          cout << edge ;
        }
        cout << endl ;
      }
     queue<int>q ;
     for(int index = 0 ; index < n ; index++){
      if(outDegree[index] == 0 ) q.push(index);
     }
     vi ans ; 
     while(!q.empty()){
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for(int edge : reverseGraph[node]){
        outDegree[edge]--;
        if(outDegree[edge] == 0 ) 
        q.push(edge);
      }
     }
     sort(ans.begin() , ans.end());
      return ans ;
    }
};
//  a node with the 0 outdegree which mean that also a  safe node ;
//  because a node alwayes connected with self ;
// pick the termial node and backword as simple that ;