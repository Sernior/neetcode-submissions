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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        levelOrdImpl(root, 0, ret);
        return ret;
    }

private:
    void levelOrdImpl(TreeNode* current, int height, vector<vector<int>>& ret){
        if(!current)return;
        if(ret.size() <= height)ret.push_back({});
        ret[height].push_back(current->val);
        levelOrdImpl(current->left, height + 1, ret);
        levelOrdImpl(current->right, height + 1, ret);
    }
};
