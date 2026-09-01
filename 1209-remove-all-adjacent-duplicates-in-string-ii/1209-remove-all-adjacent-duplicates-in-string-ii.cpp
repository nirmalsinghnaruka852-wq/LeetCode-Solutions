class Node {
public:
    char character;
    int Occuerence;
    Node(char character, int Occuerence)
        : character(character), Occuerence(Occuerence) {}
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<Node*> st;
        for (int index = 0; index < s.size(); index++) {
            char ch = s[index];
            if (!st.empty() && st.top()->character == ch)
                st.top()->Occuerence++;
            else
                st.push(new Node(ch, 1));
            if (st.top()->Occuerence == k) {
                Node* node = st.top();
                st.pop();
                delete node;
            }
        }
        string ans = "";
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            while (node->Occuerence != 0) {
                ans += node->character;
                node->Occuerence--;
            }
            delete node;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};