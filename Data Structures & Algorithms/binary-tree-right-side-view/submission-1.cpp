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
    vector<int> rightSideView(TreeNode* root) {
        int deepestSeenLevel{};
        vector<int> ret;
        rightSideViewInternal(root, deepestSeenLevel, ret, 1);
        return ret;
    }

private:
    void rightSideViewInternal(TreeNode* current, int& deepestSeenLevel, vector<int>& ret, int currentLevel){
        if (!current)return;
        if (currentLevel > deepestSeenLevel){
            ret.push_back(current->val);
            ++deepestSeenLevel;
        }
        rightSideViewInternal(current->right, deepestSeenLevel, ret, currentLevel + 1);
        rightSideViewInternal(current->left, deepestSeenLevel, ret, currentLevel + 1);
    }
};
