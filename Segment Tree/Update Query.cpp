#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&segTree, vector<int>&arr, int low, int high, int pos) {
    if(low == high) {
        segTree[pos] = arr[low];
        return;
    }

    int mid = (low + high) /2;
    
    buildTree(segTree, arr, low, mid, 2 * pos + 1);
    buildTree(segTree, arr, mid + 1, high, 2 * pos + 2);

    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

void update(vector<int>&segTree, vector<int>&arr, int low, int high, int pos, int idx, int value) {
    if(low == high) {
        arr[idx] = value;
        segTree[pos] = value;
        return;
    }

    int mid = (low + high) /2;

    if(idx <= mid) {
        update(segTree, arr, low, mid, 2 * pos + 1, idx, value);
    }
    else {
        update(segTree, arr, low, mid, 2 * pos + 2, idx, value);
    }
}

int main() {
    vector<int>arr = {1, 3, 5, 7, 9, 11, 15, 18};

    int n = arr.size();

    int x = ceil(log2(n));

    int size = 2 * (int)(pow(2, x)) - 1;

    vector<int>segTree(size, 0);

    buildTree(segTree, arr, 0, n - 1, 0);

    cout << "Original Segment Tree: " << endl;
    for(auto it : segTree) {
        cout << it << endl;
    }

    cout << endl << endl;

    int idx = 1;
    int value = 10;
    update(segTree, arr, 0, n - 1, 0, idx, value);

    buildTree(segTree, arr, 0, n - 1, 0);

    cout << "Updated Segment Tree: " << endl;
    for(auto it : segTree) {
        cout << it << endl;
    }

    return 0;
}

