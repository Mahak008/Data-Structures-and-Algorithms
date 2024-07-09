// Iterative Approach

void create_tree(node* root, vector<int>& vec) {
    queue<node*> q;
    q.push(root);
    int i = 0; // Start from the second element as the first is root

    while (!q.empty() && i < vec.size()) {
        node* current = q.front();
        q.pop();

        // Left child
        if (++i < vec.size()) {
            current->left = newNode(vec[i]);
            q.push(current->left);
        }

        // Right child
        if (++i < vec.size()) {
            current->right = newNode(vec[i]);
            q.push(current->right);
        }
    }
}

// Input: 
// nodes = [1 2 3 4 5 6 7]
// Output: 
//          1
//        /   \
//      2       3
//    /  \     /  \
//    4  5    6   7
