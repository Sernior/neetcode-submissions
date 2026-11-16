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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        size_t n = preorder.size();
        std::unordered_map<int, int> valToInorderIndex;
        for (int i = 0; i < n; ++i){
            valToInorderIndex[inorder[i]] = i;
        }
        return buildTree_rec(preorder, inorder , valToInorderIndex, 0, n - 1, 0);
    }
private:
    TreeNode* buildTree_rec(vector<int>& preorder, vector<int>& inorder,
                        std::unordered_map<int, int>& valToInorderIndex,
                        int lower, int upper, int current) {
        if (upper - lower < 0)return nullptr;
        TreeNode* root = new TreeNode(preorder[current]);
        int rootPartitionPoint = valToInorderIndex[preorder[current]];
        root->left = buildTree_rec(preorder, inorder, valToInorderIndex, lower, rootPartitionPoint - 1, current + 1);
        root->right = buildTree_rec(preorder, inorder, valToInorderIndex, rootPartitionPoint + 1, upper, current + 1 
        + (rootPartitionPoint - lower));
        return root;
    }
};
