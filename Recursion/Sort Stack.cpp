// Function to insert an element into a sorted stack
void insertSorted(stack<int>& st, int num) {
    if (st.empty() || (!st.empty() && st.top() < num)) {
        st.push(num);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertSorted(st, num);
    st.push(topElement);
}

// Function to sort the stack using recursion
void sortStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int topElement = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, topElement);
}

// Input : 5, -2, 9, -7, 3
// Output: 9, 5, 3, -2, -7 in reverse order
