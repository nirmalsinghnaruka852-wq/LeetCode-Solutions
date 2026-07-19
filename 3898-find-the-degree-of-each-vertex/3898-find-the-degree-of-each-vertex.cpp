class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
      int n = matrix.size() ; 
      vector<int>dist(n , 0 );
       for(int s = 0 ; s < n ; s++  ){
        for(int d = 0 ; d < n ; d++){
          if(matrix[s][d] == 1 ) dist[d]++ ;
        }
       } 
       return dist ; 
    }
};