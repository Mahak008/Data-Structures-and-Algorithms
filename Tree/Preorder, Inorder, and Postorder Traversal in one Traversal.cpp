#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node*left;
    Node*right;
    int data;

    Node(int val) {
        left = NULL;
        right = NULL;
        data = val;
    }
};

vector<vector<int>> preInpost(Node* root) {
    stack <pair<Node*, int>> st;
    st.push(make_pair(root, 1));
    vector<int> pre, in, post;

    if (root == NULL) return {pre, in, post};

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left) {
                st.push(make_pair(it.first->left, 1));
            }
        }

        else if(it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right) {
                st.push(make_pair(it.first->right, 1));
            }
        }

        else {
            post.push_back(it.first->data);
        }
    }

    return {pre, in, post};
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = preInpost(root);

    cout << "Preorder: ";
    for (int val : result[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for (int val : result[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int val : result[2]) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Preorder: 1 2 4 5 3 6 7 
// Inorder: 4 2 5 1 6 3 7 
// Postorder: 4 5 2 6 7 3 1 
