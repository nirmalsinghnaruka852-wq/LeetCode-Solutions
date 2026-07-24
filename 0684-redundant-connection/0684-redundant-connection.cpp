class Solution {
public:
  int find(int index, vector<int>& parentArr){
    if(parentArr[index] != index){
        parentArr[index] = find(parentArr[index], parentArr);
    }
    return parentArr[index];
}

  bool unionSet(int v1 , int v2, vector<int>& parentArr){
    int root1 = find(v1 , parentArr);
    int root2 = find(v2 , parentArr );
     if(root1 != root2 ){
      parentArr[root1] = root2;
      return false ;
     }
     return true ;
  }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size()+1;
         vector<int>parentArr(n+1); 
         for(int index = 1 ; index < parentArr.size() ; index++){
         parentArr[index] = index ;
        }
        for(int index = 0 ; index < edges.size() ; index++){
          if(unionSet(edges[index][0] ,edges[index][1], parentArr))
             return edges[index];
        }
        return edges[0] ;
    }

};