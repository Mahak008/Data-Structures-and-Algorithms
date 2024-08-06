// Leetcode - 3016

int minimumPushes(string word) {
    vector<int> freq(26, 0);

    for (char ch : word) {
        freq[ch - 'a']++;
    }

    sort(freq.begin(), freq.end(), greater<int>());
    int ans = 0;

    for (int i = 0; i < 26; i++) {
        int press = i / 8 + 1;
        ans += (freq[i] * press);
    }

    return ans;
}

// Input: word = "xyzxyzxyzxyz"
// Output: 12
  
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "x" -> one push on key 2
// "y" -> one push on key 3
// "z" -> one push on key 4
// Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
// It can be shown that no other mapping can provide a lower cost.
// Note that the key 9 is not mapped to any letter: it is not necessary to map letters to every key, but to map all the letters.
