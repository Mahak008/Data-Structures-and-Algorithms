// Row knows col but col doesn't know Row
// Ignore Diagonal Part
// All ROW of celebrity will be '0'.
// All COLUMN of celebrity will be '1' except diagonal. 

bool knows(vector<vector<int>>& M, int a, int b) {
    if (M[a][b] == 1) {
        return true;
    }
    return false;
}

int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (knows(M, a, b)) {
            st.push(b);
        } else {
            st.push(a);
        }
    }
    
    int ans = st.top();

    int z_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (M[ans][i] == 0) {
            z_cnt++;
        }
    }

    bool rowCheck = false;
    if (z_cnt == n) {
        rowCheck = true;
    }

    int o_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (M[i][ans] == 1) {
            o_cnt++;
        }
    }

    bool colCheck = false;
    if (o_cnt == n - 1) {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true) {
        return ans;
    }
    return -1;
}
