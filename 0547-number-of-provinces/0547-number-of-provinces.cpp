class Solution {
public:
    int find(int index, vector<int>& parentArr) {
        if (parentArr[index] != index) {
            parentArr[index] = find(parentArr[index], parentArr);
        }
        return parentArr[index];
    }

    void unionSet(int v1, int v2, vector<int>& parentArr) {
        int root1 = find(v1, parentArr);
        int root2 = find(v2, parentArr);

        if (root1 != root2)
            parentArr[root1] = root2;
    }

    vector<int> _init_(int length) {
        vector<int> arr(length);
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = i;
        }
        return arr;     }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> parentArr = _init_(isConnected.size());
        set<int> st;

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1)
                    unionSet(i, j, parentArr);
            }
        }

        for (int i = 0; i < parentArr.size(); i++) {
            int root = find(i, parentArr);  
                        st.insert(root);
        }

        return st.size();
    }
};