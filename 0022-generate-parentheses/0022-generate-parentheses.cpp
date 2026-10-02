class Solution {
public:
    vector<string> result;
    string s;

    void generate(int n, int open, int close) {
        if (s.size() == 2 * n) {
            result.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            generate(n, open + 1, close);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            generate(n, open, close + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0);
        return result;
    }
};