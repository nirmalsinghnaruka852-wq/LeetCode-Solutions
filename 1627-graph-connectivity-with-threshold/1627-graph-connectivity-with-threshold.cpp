using vi = vector<int>;
using vb = vector<bool>;

class Solution {
public:
    vi parent;
    vi size;
    int find(int index) {
        if (parent[index] == index)
            return index;
        return parent[index] = find(parent[index]);
    }
    void unionSet(int u, int v) {
        int root1 = find(u);
        int root2 = find(v);
        if (root1 == root2)
            return;
        else if (size[root1] > size[root2]) {
            parent[root2] = root1;
            size[root1] += size[root2];
        } else {
            parent[root1] = root2;
            size[root2] += size[root1];
        }
    }

    vector<bool> areConnected(int n, int threshold,
                              vector<vector<int>>& queries) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int index = 0; index < n + 1; index++) {
            parent[index] = index;
        }
        for (int d = threshold + 1; d <= n; d++) {

            for (int multiple = 2 * d; multiple <= n; multiple += d) {

                unionSet(d, multiple);
            }
        }
        for (int index : parent) {
            cout << index << " ";
        }
        vb ans ;
        for(vi& edge : queries ){
          int u = edge[0];
          int v = edge[1];
         if(find(u) == find(v))
              ans.push_back(true);
          else ans.push_back(false);
        }
        return ans ; 
    }
};