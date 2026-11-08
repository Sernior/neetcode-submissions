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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        bool balanced = true;
        maxDepth(root, balanced);
        return balanced;
    }

private:
    int maxDepth(TreeNode* root, bool& balanced) {
        if(!root)return 0;
        int depthLeft = maxDepth(root->left, balanced);
        int depthRight = maxDepth(root->right, balanced);
        if(std::abs(depthLeft - depthRight) > 1)balanced = false;
        return 1 + max(depthLeft, depthRight);
    }
};
