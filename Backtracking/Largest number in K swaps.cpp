void solve(string str, int k, int idx, string &ans) {
    if(k == 0 || idx == str.length()) {
        if (str.compare(ans) > 0) {
            ans = str;
        }
        return;
    }
    
    char maxChar = str[idx];
    
    for (int i = idx + 1; i < str.length(); i++) {
        if (str[i] > maxChar) {
            maxChar = str[i];
        }
    }
    
    if (maxChar != str[idx]) {
        k--; // We are making a swap, so reduce k
    }
    
    for (int i = idx; i < str.length(); i++) {
        if (str[i] == maxChar) {
            swap(str[idx], str[i]);
            solve(str, k, idx + 1, ans);
            swap(str[idx], str[i]);
        }
    }
}   

string findMaximumNum(string str, int k){
    int idx = 0;
    string ans = str;
    
    solve(str, k, idx, ans);
    return ans;
}

// Input: K = 4, str = "1234567"
// Output: 7654321
// Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5
