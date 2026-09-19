using vi = vector<int>;
using vvi = vector<vi>;

class State {
public:
    int max;
    int current;

    State(int current, int max) : max(max), current(current) {}
};

class Solution {
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    State longestPath(int node, vvi& adjList, string& s) {

        // base condition
        if (adjList[node].size() == 0)
            return State(1, 1);

        int Max = 0;
        int firstPath = 0;
        int secondPath = 0;

        for (int neb : adjList[node]) {

            State s1 = longestPath(neb, adjList, s);

            Max = max(Max, s1.max);

            if (s[node] != s[neb]) {

                int temp = s1.current;

                if (firstPath == 0)
                    firstPath = temp;
                else {
                    if (firstPath < temp)
                        swap(firstPath, temp);

                    if (secondPath < temp)
                        swap(secondPath, temp);
                }
            }
        }

        int current = 1 + firstPath + secondPath;
        Max = max(Max, current);

        return State(1 + firstPath, Max);
    }

public:
    int longestPath(vector<int>& parent, string s) {

        int n = parent.size();

        vvi adjList(n);

        for (int i = 1; i < n; i++) {
            adjList[parent[i]].push_back(i);
        }

        State ans = longestPath(0, adjList, s);

        return ans.max;
    }
};