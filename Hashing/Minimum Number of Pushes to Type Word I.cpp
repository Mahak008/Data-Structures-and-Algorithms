// Leetcode - 3014

int minimumPushes(string word) {
    unordered_map<int, int> mp;
    int assign_key = 2;
    int ans = 0;

    for (char ch : word) {
        if (assign_key > 9) {
            assign_key = 2;
        }

        mp[assign_key]++;
        ans += mp[assign_key];

        assign_key++;
    }

    return ans;
}

// Input: word = "xycdefghij"
// Output: 12
  
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> two pushes on key 2
// "c" -> one push on key 3
// "d" -> two pushes on key 3
// "e" -> one push on key 4
// "f" -> one push on key 5
// "g" -> one push on key 6
// "h" -> one push on key 7
// "i" -> one push on key 8
// "j" -> one push on key 9
// Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
