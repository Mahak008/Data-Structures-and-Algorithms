vector<int> leftSmaller(vector<int> a, int n) {
    vector<int> left(n, -1);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top().second;
        }
        st.push({a[i], i});
    }
    return left;
}

vector<int> rightSmaller(vector<int> arr, int n) {
    stack<pair<int, int>> st;
    vector<int> right(n, n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top().second;
        }
        st.push({arr[i], i});
    }
    return right;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left = leftSmaller(heights, n);
    vector<int> right = rightSmaller(heights, n);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = width * heights[i];
        if (area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
}

// Input: 2, 1, 5, 6, 2, 3
// Output: 10
