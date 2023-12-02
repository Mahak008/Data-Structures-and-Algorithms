int solve(int A) {
    int count = 0;
    while(A) {
        if(A%2 == 0) {
            count++;
        }
        else {
        break;
        }
        A /= 2;
    }
    return count;
}

// 18 in binary is represented as: 10010, there is 1 trailing zero.
// 8 in binary is represented as: 1000, there are 3 trailing zeroes.
