/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node*  dfs(Node* root, unordered_set<int>& st,
             unordered_map<int, Node*>& mp) {
        if (root == nullptr)
            return nullptr;
        if (st.count(root->val))
            return mp[root->val];
        st.insert(root->val);
        Node* newRoot = mp[root->val] = new Node(root->val);
        for (auto edge : root->neighbors) {
            if (root != nullptr) {
                if (mp.count(newRoot->val))
                    mp[newRoot->val]->neighbors.push_back(dfs(edge, st, mp));
                else
                    mp[newRoot->val]->neighbors = {dfs(edge, st, mp)};
            }
        }
        return newRoot;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node* > mp;
        unordered_set<int> st;
       
       return  dfs(node, st, mp);
         
    }
};