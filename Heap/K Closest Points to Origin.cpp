// Leetcode - 973

typedef pair<double, pair<int, int>> p;
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<vector<int>> ans;

    for (int i = 0; i < points.size(); i++) {

        int num1 = points[i][0];
        int num2 = points[i][1];
        int sum = num1 * num1 + num2 * num2;

        pq.push(make_pair(sqrt(sum), make_pair(num1, num2)));
    }

    while (k--) {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }
    return ans;
}

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
