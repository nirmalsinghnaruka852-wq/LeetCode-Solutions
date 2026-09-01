using vi = vector<int>;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vi MaxOccurrence(26, 0);
        vi Occurrence(26, 0);

        int required = 0;

        for (char ch : s) {
            MaxOccurrence[ch - 'a']++;
        }

        vi ans;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';

            Occurrence[index]++;

            if (Occurrence[index] == 1)
                required++;

            if (Occurrence[index] == MaxOccurrence[index])
                required--;

            if (required == 0) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};