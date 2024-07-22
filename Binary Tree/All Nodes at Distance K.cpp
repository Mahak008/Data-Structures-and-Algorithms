// Leetcode - 863

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->left) {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;

    q.push(target);
    visited[target] = true;

    int level = 0;

    while (!q.empty()) {
        int size = q.size();

        if (level++ == k)
            break;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }

            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if (parent_track[curr] && !visited[parent_track[curr]]) {
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
    }

    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front()->val);
        q.pop();
    }

    return res;
}

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
