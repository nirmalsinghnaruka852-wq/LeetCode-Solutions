class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        vector<pair<int, char>> freq = {
            {a, 'a'},
            {b, 'b'},
            {c, 'c'}
        };

        while (true) {
            sort(freq.rbegin(), freq.rend());

            bool added = false;

            for (int i = 0; i < 3; i++) {
                int count = freq[i].first;
                char ch = freq[i].second;

                if (count == 0)
                    continue;

                int n = ans.size();

                if (n >= 2 && ans[n - 1] == ch && ans[n - 2] == ch)
                    continue;

                ans += ch;
                freq[i].first--;
                added = true;

                break;
            }

            if (!added)
                break;
        }

        return ans;
    }
};