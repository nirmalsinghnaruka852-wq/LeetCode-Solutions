class State {
public:
    int sum;
    int totalNodes;

    State(int sum, int totalNodes)
        : sum(sum), totalNodes(totalNodes) {}
};

class Solution {
public:
    int count = 0;

    State* dfs(TreeNode* node) {
        if (node == nullptr)
            return new State(0, 0);

        const State* const leftSubTree = dfs(node->left);
        const State* const rightSubTree = dfs(node->right);

        State* root = new State(
            leftSubTree->sum + rightSubTree->sum + node->val,
            leftSubTree->totalNodes + rightSubTree->totalNodes + 1
        );

        if ((root->sum / root->totalNodes) == node->val)
            count++;

        delete leftSubTree;
        delete rightSubTree;

        return root;
    }

    int averageOfSubtree(TreeNode* root) {
        const State* const ans = dfs(root);
        delete ans;

        return count;
    }
};