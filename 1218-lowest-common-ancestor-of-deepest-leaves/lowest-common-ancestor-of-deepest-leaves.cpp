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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int deepest = 0;
        TreeNode* common_ancestor = root;
        helper(root, 0, deepest, common_ancestor);
        return common_ancestor;
    }

    int helper(TreeNode* root, int d, int& deepest, TreeNode*& com_anc) {
        deepest = max(d, deepest);
        if (!root) {
            return d;
        }

        int left = helper(root->left, d + 1, deepest, com_anc);
        int right = helper(root->right, d + 1, deepest, com_anc);
        if (left == deepest && right == deepest) {
            com_anc = root;
        }
        return max(left, right);
    }
};