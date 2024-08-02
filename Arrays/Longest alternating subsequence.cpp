int alternatingMaxLength(vector<int>& arr) {
    if (arr.empty()) return 0;

    int up = 1, down = 1;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[i - 1]) {
            up = down + 1;
        } else if (arr[i] < arr[i - 1]) {
            down = up + 1;
        }
    }

    return max(up, down);
}

// Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
// Output: 7
// Explanation: There are several subsequences that achieve this length. 
// One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
