void solve(stack<int>&st, int x) {
   while(st.empty()) {
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    solve(st, x);
    st.push(num);
}

stack<int> pushAtBottom(stack<int>&st, int x) {
    solve(st, x);
    return st;
}

// Input: x = 5, arr = 6 2 4 9
// Output: 5 6 2 4 9
