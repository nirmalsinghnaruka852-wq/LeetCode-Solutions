class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);
        vector<int> totalTime(n + 1, 0);
        for (auto edge : relations) {
            adj[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
                totalTime[i] = time[i - 1];
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int edge : adj[node]) {
                degree[edge]--;
                if (degree[edge] == 0)
                    q.push(edge);
                totalTime[edge] =
                    max(totalTime[edge], totalTime[node] + time[edge - 1]);
            }
        }
        // for(int index = 0 ; index < n ; index++){
        //   totalTime[index+1] += time[index];
        // }
        int ans = 0;
        for (int index : totalTime) {
            cout << index << endl;
        }
         for(int index : totalTime){
           ans = ans > index ? ans : index ;
         }
        return ans ;
        // return 0;
    }
};

//  FIRST  TASK IS CONVERT IT INTO THE  ADJ ;
//  AND ALSO CREATE DEGREE ARRAY ;
