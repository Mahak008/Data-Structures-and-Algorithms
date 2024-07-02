string getPermutation(int n, int k) {
    vector<int> v;
    int fact = 1;

    for (int i = 1; i < n; i++) {
        fact *= i;
        v.push_back(i);
    }
    v.push_back(n);

    string ans = "";
    k = k - 1;

    for (int i = 0; i < n; i++) {
        ans += to_string(v[k / fact]);
        v.erase(v.begin() + k / fact);

        if (v.empty()) {
            break;
        }

        k = k % fact;
        fact = fact / v.size();
    }
    return ans;
}

// Input: n = 3, k = 3
// Output: "213"

// All Permutations
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
