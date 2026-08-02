using vi = vector<int>;
using vii = vector<vector<int>>;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0;
        int target = graph.size() - 1;
        queue<vi> q;
        q.push({0});
        vii ans;
        while (!q.empty()) {
            vi node = q.front();
            q.pop();
            int lastIndex = node.size() -1 ; 
            int ele = node[node.size() - 1];
            if (node[lastIndex] == target)
                ans.push_back(node);

            else {
                for (int element : graph[ele]) {
                    //  each time create new node and push the element ;
                    vector<int> next = node;
                    next.push_back(element);
                    q.push(next);
                }
            }
        }
        return ans ; 
    }
};

//  algorithm start ;
// given adj list ;
//  make queue ;
//  push the 0 element ;
//  visited all nebighor ;
//  if we reach the last elemnt