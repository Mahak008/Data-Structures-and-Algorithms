// Leetcode - 652

string getSubTreeString(TreeNode* root, unordered_map<string, int>& mp,
                        vector<TreeNode*>& ans) {
    if (!root) {
        return "N";
    }

    string s = to_string(root->val) + " , " +
               getSubTreeString(root->left, mp, ans) + " , " +
               getSubTreeString(root->right, mp, ans);

    if (mp[s] == 1) {
        ans.push_back(root);
    }

    mp[s]++;

    return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

    getSubTreeString(root, mp, ans);

    return ans;
}

// Input: root = [1,2,3,4,null,2,4,null,null,4]
// Output: [[2,4],[4]]
