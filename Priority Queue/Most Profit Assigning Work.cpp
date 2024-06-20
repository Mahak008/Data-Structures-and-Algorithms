int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                        vector<int>& worker) {
    int n = difficulty.size();
    int m = worker.size();

    priority_queue<pair<int, int>> pq; // max heap of pairs

    for (int i = 0; i < n; i++) {
        pq.push({profit[i], difficulty[i]});
    }

    sort(worker.begin(), worker.end(),
         greater<int>()); // sort in descending order

    int i = 0, sum = 0;
    while (i < m && !pq.empty()) {
        while (!pq.empty() && pq.top().second > worker[i]) {
            pq.pop();
        }
        if (!pq.empty()) {
            sum += pq.top().first;
        }
        i++;
    }
    return sum;
}

// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
