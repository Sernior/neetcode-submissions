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
    int kthSmallest(TreeNode* root, int k) {
        int ret = -1;
        kthSmallest_dfs(root, k, ret);
        return ret;
    }
private:
    void kthSmallest_dfs(TreeNode* cur, int& k, int& ret) {
        if(!cur)return;
        kthSmallest_dfs(cur->left, k, ret);
        --k;
        if (!k) {
            ret = cur->val;
            return;
        }
        kthSmallest_dfs(cur->right, k, ret);
    }
};
