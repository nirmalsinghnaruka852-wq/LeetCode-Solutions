class Solution {
public:
    int n = 250000;
    vector<int> parent;
    vector<int> size;

    Solution() {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int index) {
        if (index == parent[index])
            return index;
        return parent[index] = find(parent[index]);
    }

    void unionSet(int u, int v) {
        int root1 = find(u);
        int root2 = find(v);

        if (root1 == root2)
            return;

        if (size[root1] > size[root2]) {
            parent[root2] = root1;
            size[root1] += size[root2];
        } else {
            parent[root1] = root2;
            size[root2] += size[root1];
        }
    }

    int size1(int id) {
        int root = find(id);
        return size[root];
    }

    int genrateId(int row, int col) {
        return row * 500 + col;    
    }

    int largestIsland(vector<vector<int>>& grid) {

        vector<pair<int, int>> dirs = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };

        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (grid[row][col] == 0)
                    continue;

                for (auto dir : dirs) {

                    int r = row + dir.first;
                    int c = col + dir.second;

                    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
                        continue;

                    unionSet(genrateId(row, col), genrateId(r, c));
                }
            }
        }

        int max1 = -1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 1)
                    continue;

                set<int> st;
                int max2 = 1;

                for (auto dir : dirs) {

                    int r = i + dir.first;
                    int c = j + dir.second;

                    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
                        continue;

                    int root = find(genrateId(r, c));

                    if (st.count(root))
                        continue;

                    max2 += size[root];
                    st.insert(root);
                }

                max1 = max(max1, max2);
            }
        }

        if (max1 == -1)
            return rows * cols;

        return max1;
    }
};