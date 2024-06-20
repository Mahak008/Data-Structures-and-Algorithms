int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int n = difficulty.size();
    int m = worker.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({difficulty[i], profit[i]});
    }
    sort(v.begin(), v.end());

    sort(worker.begin(), worker.end());

    int sum = 0, j = 0, maxProfit = 0;

    for (int i = 0; i < m; i++) {
        while (j < n && worker[i] >= v[j].first) {
            maxProfit = max(maxProfit, v[j].second);
            j++;
        }
        sum += maxProfit;
    }

    return sum;
}

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
