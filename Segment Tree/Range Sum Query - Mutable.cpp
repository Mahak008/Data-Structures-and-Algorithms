// Leetcode - 307

class NumArray {
private:
    vector<int> segTree;
    vector<int> nums;
    int n;

    void buildTree(vector<int>& segTree, vector<int>& arr, int low, int high,
                   int pos) {
        if (low == high) {
            segTree[pos] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        buildTree(segTree, arr, low, mid, 2 * pos + 1);
        buildTree(segTree, arr, mid + 1, high, 2 * pos + 2);

        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }

    void updateQuery(vector<int>& segTree, vector<int>& arr, int low, int high,
                     int pos, int idx, int value) {
        if (low == high) {
            segTree[pos] = value;
            return;
        }

        int mid = (low + high) / 2;

        if (idx <= mid) {
            updateQuery(segTree, arr, low, mid, 2 * pos + 1, idx, value);
        } else {
            updateQuery(segTree, arr, mid + 1, high, 2 * pos + 2, idx, value);
        }

        segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
    }

    int query(vector<int>& segTree, int start, int end, int low, int high,
              int pos) {
        if (low > end || high < start) {
            return 0;
        }

        if (low >= start && high <= end) {
            return segTree[pos];
        }

        int mid = (low + high) / 2;

        return query(segTree, start, end, low, mid, 2 * pos + 1) +
               query(segTree, start, end, mid + 1, high, 2 * pos + 2);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        int x = ceil(log2(n));
        int size = 2 * (int)(pow(2, x)) - 1;

        segTree = vector<int>(size, 0);
        this->nums = nums;

        buildTree(segTree, nums, 0, n - 1, 0);
    }

    void update(int index, int val) {
        if (index < 0 || index >= n) return;

        nums[index] = val;
        updateQuery(segTree, nums, 0, n - 1, 0, index, val);
    }

    int sumRange(int start, int end) {
        return query(segTree, start, end, 0, n - 1, 0);
    }
};

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
