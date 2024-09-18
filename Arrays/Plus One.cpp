// Leetcode - 66

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    // Start from the last digit and move backwards
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            // If current digit is less than 9, just add 1 and return
            digits[i]++;
            return digits;
        }
        // If digit is 9, set it to 0
        digits[i] = 0;
    }

    // If all digits are 9, we need to add an additional digit at the beginning
    digits.insert(digits.begin(), 1);
    return digits;
}

// Input: digits = [9]
// Output: [1,0]
