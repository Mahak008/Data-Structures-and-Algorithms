int subarraysWithSumK(vector <int> a, int b) {
    // Write your code here
    map <int, int> mp;
    int x = 0, cnt = 0;
    mp[x]++;
    for(int i = 0; i < a.size(); i++) {
        x ^= a[i];
        int xr = x^b;
        mp[x]++;
        cnt += mp[xr];
    }
    return cnt;
}

// Input : 1, 2, 3, 2
// b = 2

// Output: 3

// Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
