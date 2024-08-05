// Leetcode - 739

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> st;
    vector<int> ans;
    int n = temperatures.size();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first <= temperatures[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans.push_back(0);
        } else {
            ans.push_back(st.top().second - i);
        }

        st.push({temperatures[i], i});
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
