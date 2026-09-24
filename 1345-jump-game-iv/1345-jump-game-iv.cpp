using vi = vector<int>;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vi> mp;
        int n = arr.size();
        vector<bool> st(n, false);
        for (int index = 0; index < n; index++) {
            mp[arr[index]].push_back(index);
        }
        queue<int> q;
        int step = 0;
        q.push(0);
        st[0] = true ; 
        int size = q.size();
        // cout << size ; 
        while (!q.empty()) {   
            int index = q.front();
            cout << index ;
            q.pop();
            size--;
            if (index == n - 1)  return step;
            if (index - 1 >= 0 && !st[index - 1]) {
                st[index - 1] = true;
                q.push(index - 1);
            }
            if (index + 1 < n && !st[index + 1]) {
                st[index + 1] = true;
                q.push(index + 1);
            }
            for (int nebhior : mp[arr[index]]) {
                if (!st[nebhior]) {
                    st[nebhior] = true;
                    q.push(nebhior);
                }  
            }
            mp[arr[index]].clear();
             if (size == 0) {
                    size = q.size();
                    step++;
                }

        }
        return step;
    }
};
