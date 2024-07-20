// Leetcode - 653

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

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }

        return false;
    }
};

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
