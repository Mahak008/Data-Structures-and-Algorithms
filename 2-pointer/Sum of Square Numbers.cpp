bool judgeSquareSum(int c) {
    c = (int)c;
    long long a = 0, b = sqrt(c);

    while (a <= b) {
        long long sum = a * a + b * b;
        if (sum == c) {
            return true;
        } else if (sum < c) {
            a++;
        } else {
            b--;
        }
    }
    return false;
}

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
