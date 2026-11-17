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
    int maxPathSum(TreeNode* root) {
        int maxSum{root->val};
        maxPathSum_rec(root, maxSum);
        return maxSum;
    }
private:
    int maxPathSum_rec(TreeNode* cur, int& maxSum){
        if (!cur) return 0;
        int currentValue = cur->val;
        int leftValue = max(maxPathSum_rec(cur->left, maxSum), 0);
        int rightValue = max(maxPathSum_rec(cur->right, maxSum), 0);
        maxSum = max(currentValue + leftValue + rightValue, maxSum);
        return max(currentValue + leftValue, currentValue + rightValue);
    }
};
