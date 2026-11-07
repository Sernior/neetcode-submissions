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
        if (nodeToDepths.empty())maxDepth(root);
        int currentNodeDiameter = nodeToDepths[root].first + nodeToDepths[root].second;
        return max({currentNodeDiameter, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }

private:

    std::unordered_map<TreeNode*, pair<int, int>> nodeToDepths;

    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int depthLeft = maxDepth(root->left);
        int depthRight = maxDepth(root->right);
        nodeToDepths[root] = {depthLeft, depthRight};
        return max(1 + depthLeft, 1 + depthRight);
    }
};
