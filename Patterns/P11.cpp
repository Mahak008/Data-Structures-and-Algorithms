int n = 5, count = 0;
char ch = 'a', cha = 'B';
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        if(count % 2 == 0) {
            cout << ch;
            ch += 2;
        }
        else {
            cout << cha;
            cha += 2;
        }
        count++;
    }
    cout << endl;
}

// Output -
// a
// Bc
// DeF
// gHiJ
// kLmNo
