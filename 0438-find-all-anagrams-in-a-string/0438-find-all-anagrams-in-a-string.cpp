class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        
        for (int i = 0; i < p.size(); i++) {
            freq1[s[i] - 'a']++;
            freq2[p[i] - 'a']++;
        }

        int misMatch = 0;

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                misMatch++;
        }

        if (misMatch == 0)
            ans.push_back(0);

        int left = 0;

        for (int right = p.size(); right < s.size(); right++) {

            
            int remove = s[left] - 'a';

            if (freq1[remove] == freq2[remove])
                misMatch++;

            freq1[remove]--;

            if (freq1[remove] == freq2[remove])
                misMatch--;

            left++;

            
            int add = s[right] - 'a';

            if (freq1[add] == freq2[add])
                misMatch++;

            freq1[add]++;

            if (freq1[add] == freq2[add])
                misMatch--;

            if (misMatch == 0)
                ans.push_back(left);
        }

        return ans;
    }
};