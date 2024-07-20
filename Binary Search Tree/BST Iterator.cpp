// Leetcode - 173

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool rev = true; // before
    // rev = false => next

    void pushAll(TreeNode* root) {
        while (root) {
            st.push(root);
            if (rev == true) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool reverse) {
        rev = reverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (!rev) {
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }

        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
};

// Input
// ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
  
// Output - [null, 3, 7, true, 9, true, 15, true, 20, false]
