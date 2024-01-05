// XOR of numbers between L annd R (L, R)
// Xor(R) ^ XOR(L-1)

int x_o_r(int n) {
    int res;
    if(n % 4 == 0) {
        res = n;
    }
    else if(n % 4 == 1) {
        res = 1;
    }
    else if(n % 4 == 2) {
        res = n+1;
    }
    else if(n % 4 == 3) {
        res = 0;
    }
    return res;
}

int main() {
    int n = 2, m = 4;
    int a = x_o_r(n-1);
    int b = x_o_r(m);
    cout << "a ^ b = " << (a ^ b) << endl;
    return 0;
}

// Output - 5
