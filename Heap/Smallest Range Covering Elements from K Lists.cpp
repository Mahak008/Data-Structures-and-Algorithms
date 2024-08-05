// Leetcode - 632

class Node {
public:
    int data, row, col;
    Node(int val, int r, int c) {
        data = val;
        row = r;
        col = c;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) { return a->data > b->data; }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);

            pq.push(new Node(element, i, 0));
        }

        int start = mini, end = maxi;

        while (!pq.empty()) {
            Node* temp = pq.top();
            pq.pop();
            mini = temp->data;
            int row = temp->row;

            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            if (temp->col + 1 < nums[temp->row].size()) {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                pq.push(new Node(nums[temp->row][temp->col + 1], temp->row,
                                 temp->col + 1));
            } else {
                break;
            }
        }
        return {start, end};
    }
};

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
  
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
