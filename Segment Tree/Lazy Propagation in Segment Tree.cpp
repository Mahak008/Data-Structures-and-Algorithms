#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> segTree;
    vector<int> lazy;
    vector<int> nums;
    int n;

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

    void updateRangeLazy(vector<int>& segTree, vector<int>& lazy, int low, int high, int l, int r, int pos, int value) {
        if (low > high) 
          return;

        // Make sure all propagation is done at pos
        if (lazy[pos] != 0) {
            segTree[pos] += (high - low + 1) * lazy[pos];
          
            if (low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
          
            lazy[pos] = 0;
        }

        // No overlap
        if (low > r || high < l) 
          return;

        // Total overlap
        if (low >= l && high <= r) {
            segTree[pos] += (high - low + 1) * value;
            if (low != high) {
                lazy[2 * pos + 1] += value;
                lazy[2 * pos + 2] += value;
            }
            return;
        }

        // Partial overlap
        int mid = (low + high) / 2;
        updateRangeLazy(segTree, lazy, low, mid, l, r, 2 * pos + 1, value);
        updateRangeLazy(segTree, lazy, mid + 1, high, l, r, 2 * pos + 2, value);
        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }

    int queryRangeLazy(vector<int>& segTree, vector<int>& lazy, int low, int high, int l, int r, int pos) {
        if (low > high) 
          return 0;

        // Make sure all propagation is done at pos
        if (lazy[pos] != 0) {
            segTree[pos] += (high - low + 1) * lazy[pos];
          
            if (low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
          
            lazy[pos] = 0;
        }

        // No overlap
        if (low > r || high < l) 
          return 0;

        // Total overlap
        if (low >= l && high <= r) 
          return segTree[pos];

        // Partial overlap
        int mid = (low + high) / 2;
        return queryRangeLazy(segTree, lazy, low, mid, l, r, 2 * pos + 1) +
               queryRangeLazy(segTree, lazy, mid + 1, high, l, r, 2 * pos + 2);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        int x = ceil(log2(n));
        int size = 2 * (int)(pow(2, x)) - 1;

        segTree = vector<int>(size, 0);
        lazy = vector<int>(size, 0);
        this->nums = nums;

        buildTree(segTree, nums, 0, n - 1, 0);
    }

    void updateRange(int l, int r, int val) {
        updateRangeLazy(segTree, lazy, 0, n - 1, l, r, 0, val);
    }

    int sumRange(int start, int end) {
        return queryRangeLazy(segTree, lazy, 0, n - 1, start, end, 0);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    NumArray numArray(nums);

    // Test initial range sum
    cout << "Initial sum of range (0, 5): " << numArray.sumRange(0, 5) << endl; // Output: 36

    // Test range update
    numArray.updateRange(1, 3, 3);
    cout << "Sum of range (0, 5) after update: " << numArray.sumRange(0, 5) << endl; // Output: 45

    // Test another range sum
    cout << "Sum of range (1, 4): " << numArray.sumRange(1, 4) << endl; // Output: 32

    return 0;
}

// Initial sum of range (0, 5): 36
// Sum of range (0, 5) after update: 45
// Sum of range (1, 4): 33
