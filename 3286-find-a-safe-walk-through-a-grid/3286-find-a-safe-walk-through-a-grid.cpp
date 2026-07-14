class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n  = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>>dist(n , vector<int>(m , INT_MAX));
        vector<pair<int , int >>dirs = {{0, 1} , {1,0},{-1, 0} ,{0, -1}};
        deque<pair<int , int >>q;
        q.push_back({0 , 0 });
        dist[0][0] = grid[0][0];
        while(!q.empty()){
          auto node = q.front() ;
          q.pop_front() ;
          for(auto dir : dirs){
            int row = dir.first + node.first ; 
            int col = dir.second + node.second ;
            if(row < 0 || col < 0 || row >= n || col >= m) continue ;
            int newCost = dist[node.first][node.second]+ grid[row][col];
            if(newCost < dist[row][col]){
              dist[row][col] = newCost ;
              if(grid[row][col] ) q.push_back({row , col });
              q.push_front({row , col });
            }
          }
        }
        cout << dist[n-1][m-1];
        return (health - dist[n-1][m-1] ) >=1 ? true : false ;
    }
};
//  we go into the 1 part then that mean add the +1 or nothing and 
//  and at the ans return 