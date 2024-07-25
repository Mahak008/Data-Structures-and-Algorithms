// Leetcode - 501

vector<int> findMode(TreeNode* root) {
    vector<int> ans;

    if (!root) {
        return ans;
    }

    unordered_map<int, int> mp;

    TreeNode* curr = root;

    while (curr) {
        if (!curr->left) {
            mp[curr->val]++;
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;

            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                mp[curr->val]++;
                curr = curr->right;
            }
        }
    }

    int maxFreq = 0;
    for (const auto& pair : mp) {
        maxFreq = max(maxFreq, pair.second);
    }

    for (const auto& pair : mp) {
        if (pair.second == maxFreq) {
            ans.push_back(pair.first);
        }
    }

    return ans;
}

// Input: root = [1,null,2,2]
// Output: [2]
