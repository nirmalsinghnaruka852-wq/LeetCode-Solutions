class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (int index = 0; index < s.size(); index++) {

            if (!st.empty() && ((s[st.top()] == '(' && s[index] == ')') ||
                                (s[st.top()] == '{' && s[index] == '}') ||
                                (s[st.top()] == '[' && s[index] == ']')))

                st.pop();

            else
                st.push(index);
        }

        return st.empty();
    }
};