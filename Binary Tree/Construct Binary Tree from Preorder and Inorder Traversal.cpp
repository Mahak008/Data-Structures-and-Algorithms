// Leetcode - 105 

TreeNode* findTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = mp[root->val];

    int numsLeft = inRoot - inStart;

    root->left = findTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mp);
    root->right = findTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    TreeNode* root = findTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);

    return root;
}

// Time Complexity - O(N)
// Space Complexity - O(N)

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
