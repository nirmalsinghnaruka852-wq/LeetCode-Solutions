class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> dist(n, vector(m, INT_MAX));
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        dist[0][0] = 0;
        while (!q.empty()) {
            auto node = q.front();
            cout << node.first << " " << node.second << endl ;
            q.pop_front();
            int index = 0;
            for(auto dir : dirs ){
              int row =  node.first + dir.first ;
              int col = node.second + dir.second ;
              index++ ;
              //cout<< index << " " ;
              if(row < 0 ||  col < 0 || row >= n || col >= m) continue ;
              int wt = index ==  grid[node.first][node.second]  ? 0 : 1 ;
              if(dist[node.first][node.second] + wt < dist[row ][col]){
                dist[row ][col] = dist[node.first][node.second] + wt ;
                if(wt == 0 ) q.push_front({row , col });
                else q.push_back({row , col });
              }  
            }
            //cout<<endl ;
        }
        return dist[n-1][m-1];
    }
};

// that is cost not the arrow ok