void buildTree(vector<int>& segTree, vector<int>& arr, int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    buildTree(segTree, arr, low, mid, 2 * pos + 1);
    buildTree(segTree, arr, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 15, 18};
    int n = arr.size();

    //Height of segment tree 
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree 
    int max_size = 2 * (int)pow(2, x) - 1; 

    vector<int> segTree(max_size, 0);

    // Build the segment tree
    buildTree(segTree, arr, 0, n - 1, 0);

    // Print the segment tree
    cout << "Segment Tree: " << endl;
    for (int i = 0; i < max_size; ++i) {
        cout << segTree[i] << " ";
    }
    cout << endl;
}

// Segment Tree: 
//             69 
//       /            \
//     16             53
//   /     \         /   \
//  4      12       20    33
// /  \   /  \     /  \   / \
// 1  3  5    7   9   11 15 18 
