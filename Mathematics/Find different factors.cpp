int n = 88;
int a = 1, b = 1, c = 1;
for(int i = 2;i*i<=n;i++) {
    if(n % i == 0) {
        a = i;
        break;
    }
}

n = n / a;
for(int i = 2; i*i<n; i++) {
    if(n % i == 0) {
    
        if(i != a) {
            b = i;
        }
    }
}

c = n / b;
cout << a << endl << b << endl << c;

// Output -
// 2
// 4
// 11
