// Leetcode - 2096

// Time Limit Exceeded

class Solution {
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

    TreeNode* findNode(TreeNode* root, int target) {
        if (!root)
            return NULL;

        if (root->val == target)
            return root;

        TreeNode* left = findNode(root->left, target);

        if (left)
            return left;

        return findNode(root->right, target);
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        TreeNode* startNode = findNode(root, startValue);
        TreeNode* destNode = findNode(root, destValue);

        if (!startNode || !destNode)
            return ""; // One of the nodes not found

        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, string>> q;

        q.push({startNode, ""});
        visited.insert(startNode);

        string ans = "";

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* curr = it.first;
            string path = it.second;

            if (curr == destNode) {
                return path;
            }

            if (curr->left && visited.find(curr->left) == visited.end()) {
                q.push({curr->left, path + 'L'});
                visited.insert(curr->left);
            }

            if (curr->right && visited.find(curr->right) == visited.end()) {
                q.push({curr->right, path + 'R'});
                visited.insert(curr->right);
            }

            if (parent_track[curr] && visited.find(parent_track[curr]) == visited.end()) {
                q.push({parent_track[curr], path + 'U'});
                visited.insert(parent_track[curr]);
            }
        }

        return "";
    }
};

// Optimal Approach

class Solution {

    TreeNode* lca(TreeNode* root, int startValue, int destValue) {
        if (root == NULL || root->val == startValue || root->val == destValue) {
            return root;
        }

        TreeNode* left = lca(root->left, startValue, destValue);
        TreeNode* right = lca(root->right, startValue, destValue);

        if (left != NULL && right != NULL) {
            return root;
        }
        
        return left != NULL ? left : right;
    }

    bool findPath(TreeNode* lca, int startValue, string& s) {
        if (!lca)
            return false;

        if (lca->val == startValue)
            return true;

        s.push_back('L');
        if(findPath(lca->left, startValue, s)) {
            return true;
        }

        s.pop_back();

        s.push_back('R');
        if(findPath(lca->right, startValue, s)) {
            return true;
        }

        s.pop_back();
        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaa = lca(root, startValue, destValue);

        string lcaToSrc = "";
        string lcaToDest = "";

        findPath(lcaa, startValue, lcaToSrc);
        findPath(lcaa, destValue, lcaToDest);

        string res = "";

        for (int i = 0; i < lcaToSrc.length(); i++) {
            res += 'U';
        }

        res += lcaToDest;

        return res;
    }
};

// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
