// Leetcode - 987

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        TreeNode* node = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;

        nodes[x][y].insert(node->val);

        if (node->left) {
            q.push({node->left, {x - 1, y + 1}});
        }

        if (node->right) {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;

    for (auto it : nodes) {
        vector<int> v;

        for (auto i : it.second) {
            v.insert(v.end(), i.second.begin(), i.second.end());
        }

        ans.push_back(v);
    }

    return ans;
}

// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
