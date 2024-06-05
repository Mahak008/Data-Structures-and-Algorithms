
vector<int> leftSmaller(vector<int>& arr, int n) {
    vector<int> left(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = -1;
        } else {
            left[i] = st.top();
        }
        st.push(i);
    }
    return left;
}

vector<int> rightSmaller(vector<int>& arr, int n) {
    vector<int> right(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n;
        } else {
            right[i] = st.top();
        }
        st.push(i);
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
