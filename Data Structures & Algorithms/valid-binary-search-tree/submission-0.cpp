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
    bool isValidBST(TreeNode* root) {
        bool ret = true;
        isValidBST_dfs(root, -1000000001, 1000000001, ret);
        return ret;
    }
private:
    void isValidBST_dfs(TreeNode* current, int lower, int upper, bool& ret){
        if(!current)return;
        int const cv = current->val;
        if(cv < upper && cv > lower){
            isValidBST_dfs(current->right, cv, upper, ret);
            isValidBST_dfs(current->left, lower, cv, ret);
            return;
        }
        ret = false;
    }
};
