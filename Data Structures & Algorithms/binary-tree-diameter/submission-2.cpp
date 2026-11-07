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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)return 0;
        int depthLeft = maxDepth(root->left);
        int depthRight = maxDepth(root->right);
        return max({depthLeft + depthRight, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }

private:

    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};
