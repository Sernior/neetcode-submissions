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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)return nullptr;
        auto current = root;
        if (current->left || current->right){
            auto tmp = current->left;
            current->left = current->right;
            current->right = tmp;
            invertTree(current->left);
            invertTree(current->right);
        }
        return root;
    }
};
