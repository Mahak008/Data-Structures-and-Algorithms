class NodeValue {
    public:
    int minVal, maxVal, maxSize;
    
    NodeValue(int minVal, int maxVal, int maxSize) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution{
    private:
    NodeValue solve(Node* root) {
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
    
        auto left = solve(root->left);
        auto right = solve(root->right);
    
        if(left.maxVal < root->data && root->data < right.minVal) {
            return NodeValue(min(root->data,left.minVal), max(root->data, right.maxVal), 1 + left.maxSize + right.maxSize);
        }
    
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right. maxSize));
    }

    public:
    int largestBst(Node *root) {
        return solve(root).maxSize;
    }
};

// Input:    6
//         /   \
//       6      2              
//        \    / \
//         2  1   3
// Output: 3
// Explanation: The following sub-tree is a BST of size 3:  2
//                                                        /   \
//                                                       1     3
