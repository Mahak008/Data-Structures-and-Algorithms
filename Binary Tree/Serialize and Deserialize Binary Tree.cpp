// Leetcode - 297

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (!root)
        return "";

    string ans = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if (!cur) {
            ans += "null,";
        } else {
            ans += (to_string(cur->val) + ",");
            q.push(cur->left);
            q.push(cur->right);
        }
    }

    if (!ans.empty()) {
        ans.pop_back();
    }

    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.length() == 0)
        return NULL;

    stringstream s(data);
    string str;

    getline(s, str, ',');

    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (getline(s, str, ',')) {

            if (str == "null") {
                curr->left = NULL;
            } else {
                TreeNode* left = new TreeNode(stoi(str));
                curr->left = left;
                q.push(left);
            }
        }

        if (getline(s, str, ',')) {

            if (str == "null") {
                curr->right = NULL;
            } else {
                TreeNode* right = new TreeNode(stoi(str));
                curr->right = right;
                q.push(right);
            }
        }
    }

    return root;
}

// Time Complexity - O(N)
// Space Complexity - O(N)

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
