long long findNth(long long n) {
    int i = 1;
    long l = n % 9;
    n = n / 9;

    while(n > 0){
        l = ((n % 9) * (long)pow(10, i)) + l;
        n = n / 9;
        ++i;
    }
    return l;
}

// Input: n = 9
// Output: 10
// Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.
