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
        int ret{root->val};
        kthSmallest_dfs(root, k, ret);
        return ret;
    }
private:
    void kthSmallest_dfs(TreeNode* current, int& k, int& ret) {
        if(!current){
            return;
        }
        kthSmallest_dfs(current->left, k, ret);
        --k;
        if (k<0)return;
        if (k==0){
            ret = current->val;
        }
        kthSmallest_dfs(current->right, k, ret);
    }
};
