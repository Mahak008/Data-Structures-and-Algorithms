typedef pair<int, int> P;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {
        pq.push(make_pair(abs(arr[i] - x), arr[i]));
    }
    while (k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
