// Leetcode - 2196

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    if (descriptions.empty())
        return NULL;

    unordered_map<int, TreeNode*> mp;
    unordered_set<int> childNode; // nodes which can never be root

    for (vector<int>& v : descriptions) { // O(N)
        int parent = v[0];
        int child = v[1];
        int isLeft = v[2];

        if (mp.find(parent) == mp.end()) {
            mp[parent] = new TreeNode(parent);
        }

        if (mp.find(child) == mp.end()) {
            mp[child] = new TreeNode(child);
        }

        if (isLeft == 1) {
            mp[parent]->left = mp[child];
        } else {
            mp[parent]->right = mp[child];
        }

        childNode.insert(child);
    }

    // Find root
    for (vector<int>& v : descriptions) { // O(N)
        int parent = v[0];
        if (childNode.find(parent) == childNode.end()) {
            return mp[parent];
        }
    }

    return NULL;
}

// Time Complexity - O(N)
// Space Complexity - O(N)

// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
