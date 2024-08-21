// Leetcode - 455

int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    int l = 0, r = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (l < n && r < m) {
        if (g[l] <= s[r]) {
            l += 1;
        }
        r += 1;
    }

    return l;
}

// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
// And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 cont
