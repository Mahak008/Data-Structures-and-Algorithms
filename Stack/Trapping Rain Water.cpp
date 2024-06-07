int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    stack<int> st;
    int water = 0;

    for (int i = 0; i < n; ++i) {
        // While the current height is greater than the height at the top of the stack
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();

            if (st.empty()) break;

            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];
            water += distance * bounded_height;
        }
        st.push(i);
    }

    return water;
}

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
