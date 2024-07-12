// Leetcode - 8

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

// Example 1:
// Input: s = "42"
// Output: 42

// Explanation:
// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
// Step 3: "42" ("42" is read in)


// Example 2:
// Input: s = " -042"
// Output: -42

// Explanation:
// Step 1: "   -042" (leading whitespace is read and ignored)
// Step 2: "   -042" ('-' is read, so the result should be negative)
// Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)


// Example 3:
// Input: s = "1337c0d3"
// Output: 1337

// Explanation:
// Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
// Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
// Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
