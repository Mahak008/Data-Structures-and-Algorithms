// Leetcode - 435

static bool Comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), Comp);
    int n = intervals.size();
    int ans = 0;

    int prevEnd = intervals[0][1];

    for (int i = 1; i < n; i++) {
        int curStart = intervals[i][0];
        int curEnd = intervals[i][1];

        if (curStart < prevEnd) {
            ans++;
        } else {
            prevEnd = curEnd;
        }
    }

    return ans;
}

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
