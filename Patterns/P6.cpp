int n = 5, i, j;
for(i = 1; i <= 2*n - 1; i++) {
    int stars = i;
    if(i > n) {
        stars = 2*n - i;
    }
    // stars
    for(j = 1; j <= stars; j++) {
        cout << "*";
    }
    cout << endl;

}

// Output -
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
