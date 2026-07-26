using vi = vector<int>;
using vb = vector<bool>;
using Matrix = vector<vi>;

class Comparator {
public:
    bool operator()(const vi& a, const vi& b) const { return a[2] < b[2]; }
};

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
    return;
    }
   vb distanceLimitedPathsExist(int n, Matrix& edgeList, Matrix& queries) {
    parent.resize(n);
    size.resize(n, 1);
    vb ans(queries.size(), false);
    for (int index = 0; index < n; index++) {
        parent[index] = index;
    }
    Comparator cmp;

    sort(edgeList.begin(), edgeList.end(), cmp);

    for (int i = 0; i < queries.size(); i++)
        queries[i].push_back(i);

    sort(queries.begin(), queries.end(), cmp);
        int index2 =0 ; 
    for (int index = 0 ; index < queries.size(); index++) {
        while (index2 < edgeList.size() &&
               edgeList[index2][2] < queries[index][2]) {
            unionSet(edgeList[index2][1], edgeList[index2][0]);
            index2++;
        }
        if (find(queries[index][1]) == find(queries[index][0]))
            ans[queries[index][3]] = true;
    }
    return ans ;
}};