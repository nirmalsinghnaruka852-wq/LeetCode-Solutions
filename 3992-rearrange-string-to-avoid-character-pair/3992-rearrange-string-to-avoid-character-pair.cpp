class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans;

        for (char ch : s) {
            if (ch == y)
                ans += ch;
        }

      
        for (char ch : s) {
            if (ch != y)
                ans += ch;
        }

        return ans;
    }
};