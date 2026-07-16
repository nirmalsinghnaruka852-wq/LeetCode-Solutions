class Solution {
public:
    int find(int index , vector<int>&parent ){
      if(index == parent[index]) return index ;
      return find(parent[index] , parent);
    }
    void union1(int u, int v, vector<int>& parent) {
    int root1 = find(u, parent);
    int root2 = find(v, parent);

    if (root1 != root2) {
        parent[root2] = root1;
    }
}
  

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<int>parent(n , 0 );
      for(int index = 0 ; index < n  ; index++){
        parent[index] = index;
      }  
      for(auto edge : edges ){
          union1(edge[0] , edge[1] , parent);
      }
      return find(source, parent) == find(destination , parent);
    }
};