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
    bool isBalanced(TreeNode* root, bool isBalanced = true) {
        if(!root)return true;
        maxDepth(root, isBalanced);
        return isBalanced;
    }

private:
    int maxDepth(TreeNode* root, bool& isBalanced) {
        if(!root)return 0;
        int depthLeft = maxDepth(root->left, isBalanced);
        int depthRight = maxDepth(root->right, isBalanced);
        if(std::abs(depthLeft - depthRight) > 1)isBalanced = false;
        return 1 + max(depthLeft, depthRight);
    }
};
