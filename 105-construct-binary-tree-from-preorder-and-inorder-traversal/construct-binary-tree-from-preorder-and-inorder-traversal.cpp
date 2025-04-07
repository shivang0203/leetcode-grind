/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void createMapping(unordered_map<int, int> &valueToIndex, vector<int> &inorder) {
        for (int i = 0; i<inorder.size(); i++) {
            valueToIndex[inorder[i]] = i;
        }
        return;
    }

    int getIndexInorder(vector<int> &inorder, int &target, int &inorderStart, int &inorderEnd) {
        for (int i = inorderStart; i<=inorderEnd; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* construct(unordered_map<int, int> &valMap, vector<int>& preorder, vector<int>& inorder, int &preOrderInd, int inorderStart, int inorderEnd, int size) {

        if (preOrderInd >= size) {
            return NULL;
        }
        if (inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[preOrderInd];
        preOrderInd++;
        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = valMap[element]; 
        root->left = construct(valMap, preorder, inorder, preOrderInd, inorderStart, elementIndexInsideInorder-1, size);
        root->right = construct(valMap, preorder, inorder, preOrderInd, elementIndexInsideInorder+1, inorderEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderInd = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int size = inorder.size();

        unordered_map<int, int> valMap;
        createMapping(valMap, inorder);

        TreeNode* root = construct(valMap, preorder, inorder, preOrderInd, inorderStart, inorderEnd, size);

        return root;
    }
};