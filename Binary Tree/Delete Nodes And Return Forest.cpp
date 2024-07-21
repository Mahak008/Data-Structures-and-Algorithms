// Leetcode - 1110

TreeNode* deleteNode(TreeNode* root, unordered_set<int>& s,
                     vector<TreeNode*>& ans) {
    if (!root) {
        return NULL;
    }

    root->left = deleteNode(root->left, s, ans);
    root->right = deleteNode(root->right, s, ans);

    if (s.find(root->val) != s.end()) {
        if (root->left) {
            ans.push_back(root->left);
        }

        if (root->right) {
            ans.push_back(root->right);
        }

        return NULL;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> s;

    for (auto it : to_delete) {
        s.insert(it);
    }

    deleteNode(root, s, ans);

    if (s.find(root->val) == s.end()) {
        ans.push_back(root);
    }

    return ans;
}

// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
