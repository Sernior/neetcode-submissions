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
    int goodNodes(TreeNode* root) {
        int numOfGoodNodes = 0;
        goodNodes_dfs(root, -101, numOfGoodNodes);
        return numOfGoodNodes;
    }

private:
    void goodNodes_dfs(TreeNode* current, int pathMax, int& numOfGoodNodes){
        if (!current)return;
        if (current->val >= pathMax){
            ++numOfGoodNodes;
            pathMax = current->val;
        }
        goodNodes_dfs(current->left, pathMax, numOfGoodNodes);
        goodNodes_dfs(current->right, pathMax, numOfGoodNodes);
    }
};
