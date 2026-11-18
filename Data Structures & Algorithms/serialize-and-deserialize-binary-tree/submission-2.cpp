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

class Codec {
public:
// [{IDCurrent, ValueCurrent, IDLeft, IDRight}]
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string r("");
        int uID{};
        std::vector<Entry> entries;
        serialize_dfs(root, entries, uID);
        for (Entry& e : entries){
            r.append(std::format("{} {} {} {} ", e.uID, e.val ,e.uIDL, e.uIDR));
        }
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<Entry> entries;
        std::istringstream in(data);
        Entry e;
        while (in >> e.uID >> e.val >> e.uIDL >> e.uIDR) {
            entries.push_back(e);
        }
        if (entries.empty()) return nullptr;
        std::vector<TreeNode*> nodes(entries.size());
        for (Entry const& x : entries) nodes[x.uID] = new TreeNode(x.val);
        for (Entry const& x : entries) {
            if (x.uIDL != -1) nodes[x.uID]->left = nodes[x.uIDL];
            if (x.uIDR != -1) nodes[x.uID]->right = nodes[x.uIDR];
        }
        return nodes[0];
    }

private:

    struct Entry {
        int uID;
        int val;
        int uIDL;
        int uIDR;
    };

    void serialize_dfs(TreeNode* cur, std::vector<Entry>& entries, int& uID) {
        if (!cur) return;
        Entry e{uID, cur->val, -1, -1};
        if (cur->left){
            ++uID;
            e.uIDL = uID;
            serialize_dfs(cur->left, entries, uID);
        }
        if (cur->right){
            ++uID;
            e.uIDR = uID;
            serialize_dfs(cur->right, entries, uID);
        }
        entries.push_back(e);
    }

};
