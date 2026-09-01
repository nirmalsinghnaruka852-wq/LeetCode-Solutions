class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        for (int index = 0; index < num.size(); index++) {
            int number = num[index] - '0';

            while (!st.empty() && k != 0 && st.top() > number) {
                st.pop();
                k--;
            }

            st.push(number);
        }

        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";

        while (!st.empty()) {
            ans += char(st.top() + '0');
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while (i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};