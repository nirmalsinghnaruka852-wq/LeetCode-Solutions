class Solution {
public:
    vector<int> parentArr;
    vector<int> size;

    int find(int index) {
        if (index == parentArr[index]) return index;
        return parentArr[index] = find(parentArr[index]);
    }

    void unionSet(int u, int v) {
        int root1 = find(u);
        int root2 = find(v);

        if (root1 == root2) return;

        if (size[root1] > size[root2]) {
            parentArr[root2] = root1;
            size[root1] += size[root2];
        } else {
            parentArr[root1] = root2;
            size[root2] += size[root1];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        parentArr.resize(n);
        size.resize(n, 1);

        for (int index = 0; index < n; index++) {
            parentArr[index] = index;
        }

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            unionSet(u, v);
        }

        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(find(i)); 
        }

        return st.size() - 1;
    }
};