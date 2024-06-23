int myAtoi(string s) {
    int res = 0;
    int i = 0;
    int sign = 1;
    int n = s.length();

    // Skip leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Check for the sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < n) {
        if (s[i] < '0' || s[i] > '9') {
            break; // Break if the character is not a digit
        }

        int digit = s[i] - '0';

        // Check for overflow and underflow
        if (res > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        res = res * 10 + digit;
        i++;
    }

    return res * sign;
}

// Input: s = " -042"
// Output: -42
