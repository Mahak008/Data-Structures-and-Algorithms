// Leetcode - 106

TreeNode* findTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp) {
    if (postStart > postEnd || inStart > inEnd)
        return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int inRoot = mp[root->val];

    int numsLeft = inRoot - inStart;

    root->left = findTree(postorder, postStart, postStart + numsLeft - 1,inorder, inStart, inRoot - 1, mp);
    root->right = findTree(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size())
        return NULL;
    map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    TreeNode* root = findTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);

    return root;
}

// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
