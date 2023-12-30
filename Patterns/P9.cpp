int n = 5;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n-i; j++) {
        cout << " ";
    }
    int num = 1;
    for(int k = 0; k < 2*i+1; k++) {
        if(k < 2*i/2) {
            cout << num++;
        }
        else {
            cout << num--;
        }
    }
    cout << endl;
}

// Output -
//      1
//     121
//    12321
//   1234321
//  123454321
