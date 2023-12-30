int n = 5, space = 0;
for(int i = 0; i < n; i++) {
    for(int j = 1; j <= n-i; j++) {
        cout << j;
    }
    for(int j = 0; j < space; j++) {
        cout << " ";
    }
    for(int j = n-i; j> 0; j--) {
        cout << j;
    }
    space += 2;
    cout << endl;
}

// Output -
// 1234554321
// 1234  4321
// 123    321
// 12      21
// 1        1
