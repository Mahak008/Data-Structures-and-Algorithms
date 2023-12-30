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
