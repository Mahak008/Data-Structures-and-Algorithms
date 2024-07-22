// Leetcode - 1530

vector<int> solve(TreeNode* root, int distance, int& goodLeafNodes) {
    if (!root) {
        return {0};
    }

    if (!root->left && !root->right) {
        return {1};
    }

    vector<int> left = solve(root->left, distance, goodLeafNodes);
    vector<int> right = solve(root->right, distance, goodLeafNodes);

    for (int& l : left) {
        for (int& r : right) {
            if (l != 0 && r != 0 && l + r <= distance) {
                goodLeafNodes++;
            }
        }
    }

    vector<int> res;

    for (int& l : left) {
        if (l != 0 && l + 1 <= distance) {
            res.push_back(l + 1);
        }
    }

    for (int& r : right) {
        if (r != 0 && r + 1 <= distance) {
            res.push_back(r + 1);
        }
    }

    return res;
}

int countPairs(TreeNode* root, int distance) {
    int goodLeafNodes = 0;
    solve(root, distance, goodLeafNodes);
    return goodLeafNodes;
}

// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
