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
    void createMapping(unordered_map<int, int>& valMap, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            valMap[inorder[i]] = i;
        }
    }

    TreeNode* construct(unordered_map<int, int>& valMap, vector<int>& inorder,
                        vector<int>& postorder, int& postorderInd,
                        int inorderStart, int inorderEnd) {
        if (postorderInd < 0)
            return NULL;
        if (inorderStart > inorderEnd)
            return NULL;

        TreeNode* root = new TreeNode(postorder[postorderInd]);
        int elementIndex = valMap[postorder[postorderInd]];
        postorderInd--;

        root->right = construct(valMap, inorder, postorder, postorderInd,
                                elementIndex + 1, inorderEnd);
        root->left = construct(valMap, inorder, postorder, postorderInd,
                               inorderStart, elementIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderInd = postorder.size() - 1;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;

        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);

        TreeNode* root = construct(valMap, inorder, postorder, postorderInd,
                                   inorderStart, inorderEnd);

        return root;
    }
};