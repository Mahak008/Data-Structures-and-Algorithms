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

void reverseStack(stack<int> &stack) {
    if(stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    solve(stack, num);
}

// Input: 1, 2, 3, 4, 5 
// Output: 5, 4, 3, 2, 1
