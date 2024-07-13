// Leetcode - 2751

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths,
                                  string directions) {
    int n = positions.size();
    vector<int> actual_index(n);

    for (int i = 0; i < n; i++) {
        actual_index[i] = i;
    }

    auto lambda = [&](int& i, int& j) { return positions[i] < positions[j]; };

    sort(actual_index.begin(), actual_index.end(), lambda);

    stack<int> st;

    for (int& idx : actual_index) {
        if (directions[idx] == 'R') {
            st.push(idx);
        } else {
            while (!st.empty() && healths[idx] > 0) {
                int top_idx = st.top();
                st.pop();

                if (healths[idx] > healths[top_idx]) {
                    healths[top_idx] = 0;
                    healths[idx] -= 1;
                } else if (healths[idx] < healths[top_idx]) {
                    healths[top_idx] -= 1;
                    healths[idx] = 0;
                    st.push(top_idx);
                } else {
                    healths[top_idx] = 0;
                    healths[idx] = 0;
                }
            }
        }
    }

    vector<int> res;
    for (int i = 0; i < healths.size(); i++) {
        if (healths[i] > 0)
            res.push_back(healths[i]);
    }

    return res;
}

// Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// Output: [14]
