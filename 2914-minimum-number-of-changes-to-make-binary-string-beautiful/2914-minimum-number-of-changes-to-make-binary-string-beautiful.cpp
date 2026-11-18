class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int minimumOperations = 0;

        for (int index = 0; index < n; index += 2) {
            if (s[index] != s[index + 1]) {
                minimumOperations++;
            }
        }

        return minimumOperations;
    }
};

