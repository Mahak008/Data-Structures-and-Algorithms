// Leetcode - 592

string fractionAddition(string exp) {
    int num = 0, den = 1, i = 0;
    int l = exp.length();

    while (i < l) {
        int curNum = 0, curDen = 0;
        bool isNeg = false;

        // Check for sign
        if (exp[i] == '-') {
            isNeg = true;
            i++;
        } else if (exp[i] == '+') {
            i++;
        }

        // Parse numerator
        while (i < l && isdigit(exp[i])) {
            curNum = curNum * 10 + (exp[i] - '0');
            i++;
        }

        i++; // Skip the '/' character

        // Parse denominator
        while (i < l && isdigit(exp[i])) {
            curDen = curDen * 10 + (exp[i] - '0');
            i++;
        }

        if (isNeg) {
            curNum *= -1;
        }

        // Update overall fraction
        num = num * curDen + curNum * den;
        den = den * curDen;
    }

    // Simplify the fraction
    int gcd = __gcd(abs(num), abs(den));
    num /= gcd;
    den /= gcd;

    return to_string(num) + "/" + to_string(den);
}


// Input: expression = "-1/2+1/2"
// Output: "0/1"
