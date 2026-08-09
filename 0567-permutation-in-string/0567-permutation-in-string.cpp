class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int unMatched = 0;

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                unMatched++;
        }

        if (unMatched == 0)
            return true;

        int left = 0;

        for (int right = s1.size(); right < s2.size(); right++) {

            int remove = s2[left] - 'a';

            if (freq2[remove] == freq1[remove])
                unMatched++;

            freq2[remove]--;

            if (freq2[remove] == freq1[remove])
                unMatched--;

            left++;

            int add = s2[right] - 'a';

            if (freq2[add] == freq1[add])
                unMatched++;

            freq2[add]++;

            if (freq2[add] == freq1[add])
                unMatched--;

            if (unMatched == 0)
                return true;
        }

        return false;
    }
};