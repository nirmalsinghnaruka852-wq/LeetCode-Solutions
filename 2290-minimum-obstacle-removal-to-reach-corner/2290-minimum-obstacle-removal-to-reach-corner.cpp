class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m =   grid[0].size() ;
        deque<pair<int , int >>q ;
        vector<vector<int>>dist(n, vector<int>(m , INT_MAX));
       vector<pair<int , int>>dirs = {{0 , 1}, {1 , 0},{-1 , 0} ,{0 , -1}};
        q.push_back({0 , 0 });
        dist[0][0]= 0 ;
       while(!q.empty()){
        auto node = q.front() ;
        q.pop_front() ;
        for(auto dir : dirs ){
            int row = dir.first + node.first ;
            int col = dir.second + node.second ;
            if(row < 0 || col < 0 ||  row >= n || col >= m ) continue ;
            if(  dist[node.first ][node.second] + grid[row ][col] < dist[row][col])
            {
            int newCost =  dist[node.first][node.second] + grid[row ][col] ; 
             dist[row][col] = newCost ; 
              if(grid[row ][col] ) q.push_back({row , col });
              else q.push_front({row , col });
            }
        }

       }
       return dist[n-1][m-1];
    }
};

// there is the issue of the  