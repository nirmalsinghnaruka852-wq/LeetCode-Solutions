class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;
        int components;

        DSU(int n) {
            parent.resize(n + 1);
            size.assign(n + 1, 1);
            components = n;

            for (int i = 1; i <= n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        bool unionSet(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv)
                return false;

            if (size[pu] < size[pv])
                swap(pu, pv);

            parent[pv] = pu;
            size[pu] += size[pv];
            components--;

            return true;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[0] > b[0];
             });

        DSU alice(n);
        DSU bob(n);

        int remove = 0;

        for (auto &edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3) {
                bool usedAlice = alice.unionSet(u, v);
                bool usedBob = bob.unionSet(u, v);

                if (!usedAlice && !usedBob)
                    remove++;
            }
            else if (type == 1) {
                if (!alice.unionSet(u, v))
                    remove++;
            }
            else {
                if (!bob.unionSet(u, v))
                    remove++;
            }
        }

        if (alice.components != 1 || bob.components != 1)
            return -1;

        return remove;
    }
};