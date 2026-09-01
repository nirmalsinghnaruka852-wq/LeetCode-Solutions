class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string ans;

        int i = 25;  

        while (i >= 0) {

            if (freq[i] == 0) {
                i--;
                continue;
            }

            int take = min(freq[i], repeatLimit);

            ans.append(take, char('a' + i));
            freq[i] -= take;

            if (freq[i] == 0)
                continue;

            int j = i - 1;

            while (j >= 0 && freq[j] == 0)
                j--;

            if (j < 0)
                break;

            ans.push_back(char('a' + j));
            freq[j]--;

            }

        return ans;
    }
};