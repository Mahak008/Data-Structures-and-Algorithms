// Leetcode - 295

class MedianFinder {
public:
    priority_queue<int>left; // max-heap
    priority_queue<int, vector<int>, greater<int>> right; //min-heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num); 
        }

       // Balance the heaps
        if(left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            return (double)(left.top() + right.top())/2;
        }

        return left.top();
    }
};

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]
