class Solution {
public:
    struct trieNode {
        trieNode* left;  
        trieNode* right; 
        int lmini;
        int rmini;

        trieNode() {
            left = NULL;
            right = NULL;
            lmini = INT_MAX;
            rmini = INT_MAX;
        }
    };

    void insert(trieNode* root, int num) {
        trieNode* pr = root;
        for (int i = 31; i >= 0; i--) {
            bool it = (1 << i) & num;
            if (!it) {
                if (pr->left == NULL) {
                    pr->left = new trieNode();
                }
                pr->lmini = min(pr->lmini, num);  
                pr = pr->left;
            } else {
                if (pr->right == NULL) {   
                    pr->right = new trieNode();
                }
                pr->rmini = min(pr->rmini, num);  
                pr = pr->right;
            }
        }
    }

    int findvalue(int num, int m, trieNode* root) {
        int val = 0;
        trieNode* pr = root;

        for (int i = 31; i >= 0; i--) {
            bool it = (1 << i) & num;

            if (it) {
                if (pr->left && pr->lmini <= m) {
                    val += (1 << i);  
                    pr = pr->left;
                } else if (pr->right && pr->rmini <= m) {
                    pr = pr->right;
                } else {
                    return -1;  
                }
            } else {
                if (pr->right && pr->rmini <= m) {
                    val += (1 << i);  
                    pr = pr->right;
                } else if (pr->left && pr->lmini <= m) {
                    pr = pr->left;
                } else {
                    return -1;  
                }
            }
        }

        return val;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        trieNode* root = new trieNode();

        for (int num : nums) {
            insert(root, num);
        }

        vector<int> ans;

        for (auto it : queries) {
            int x = it[0];
            int m = it[1];

            int val = findvalue(x, m, root);
            ans.push_back(val);
        }

        return ans;
    }
};