int n = 5;
for(int i = 1; i <= n; i++) {
    int val = i;
    for (int j = 1; j <= i; j++) {
        cout << val++;
    }
    cout << endl;
}

// Output - 
// 1
// 23
// 345
// 4567
// 56789

int n = 5;
for(int i = 1; i <= n; i++) {
    int val = i;
    for (int j = 1; j <= i; j++) {
        cout << val--;
    }
    cout << endl;
}

// Output - 
// 1
// 21
// 321
// 4321
// 54321

int n = 5;
for(int i = 0; i < n; i++) {
    int val = n-i;
    for (int j = 0; j <= i; j++) {
        cout << val++;
    }
    cout << endl;
}

// Output - 
// 5
// 45
// 345
// 2345
// 12345
