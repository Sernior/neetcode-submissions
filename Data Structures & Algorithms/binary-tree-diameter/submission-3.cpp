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
        std::unordered_map<TreeNode*, pair<int, int>> nodeToDepths;
        if (nodeToDepths.empty())maxDepth(root, nodeToDepths);
        int currentNodeDiameter = nodeToDepths[root].first + nodeToDepths[root].second;
        return max({currentNodeDiameter, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }

private:

    int maxDepth(TreeNode* root, std::unordered_map<TreeNode*, pair<int, int>>& nodeToDepths) {
        if(!root)return 0;
        int depthLeft = maxDepth(root->left, nodeToDepths);
        int depthRight = maxDepth(root->right, nodeToDepths);
        nodeToDepths[root] = {depthLeft, depthRight};
        return max(1 + depthLeft, 1 + depthRight);
    }
};
