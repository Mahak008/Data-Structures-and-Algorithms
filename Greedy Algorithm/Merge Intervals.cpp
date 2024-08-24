// Leetcode - 56
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;

    if (intervals.empty())
        return res;
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    int curStart = intervals[0][0];
    int curEnd = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= curEnd) {
            curEnd = max(curEnd, intervals[i][1]);
        } else {
            res.push_back({curStart, curEnd});
            curStart = intervals[i][0];
            curEnd = intervals[i][1];
        }
    }
    res.push_back({curStart, curEnd});
    return res;
}

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
