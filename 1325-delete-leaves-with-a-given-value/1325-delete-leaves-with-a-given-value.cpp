/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* remover(TreeNode* node, int target)
    {
        if (node == nullptr)
            return nullptr;
         node->left = remover(node->left, target);
         node->right = remover(node->right, target);
         if (node->left == nullptr && node->right == nullptr &&
            node->val == target)
            return nullptr;
        return node;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      return remover(root , target);
    }
};