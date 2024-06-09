string removeKdigits(string num, int k) {
    if (num.length() == k)
        return "0";

    stack<char> st;
    string ans = "";

    for (int i = 0; i < num.length(); i++) {
        while (!st.empty() && st.top() > num[i] && k > 0) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    // Remove remaining digits from the end if k > 0
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    int start = 0;
    while (start < ans.size() && ans[start] == '0') {
        start++;
    }

    ans = ans.substr(start);

    return ans.empty() ? "0" : ans;
}

// Input: num = "1432219", k = 3
// Output: "1219"

Input: num = "112", k = 1
Output: "11"
