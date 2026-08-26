class Solution {
public:
    void sweper(int start, int end, string& s) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();

        for (int start = 0; start < n; start += 2 * k) {
            int end = min(start + k - 1, n - 1);
            sweper(start, end, s);
        }

        return s;
    }
};