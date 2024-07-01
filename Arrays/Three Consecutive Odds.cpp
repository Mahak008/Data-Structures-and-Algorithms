bool threeConsecutiveOdds(vector<int>& arr) {
    if (arr.size() < 3) {
        return false; // Not enough elements to have three consecutive odds
    }

    for (int i = 0; i < arr.size() - 2; i++) {
        if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
            return true;
        }
    }
    return false;
}

// Input: arr = 1, 2, 34, 3, 4, 5, 7, 23, 12
// Output: true
// Explanation: [5,7,23] are three consecutive odds.
