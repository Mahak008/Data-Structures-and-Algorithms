int n = 4, i, j;
for(i = 0; i < 2*n - 1; i++) {
    for(j = 0; j < 2*n - 1; j++) {
        int top = i;
        int left = j;
        int right = (2*n-2)-j;
        int down = (2*n-2)-i;
        cout << (n - min(min(top, down), min(left, right))) << " ";
    }
    cout << endl;
}

// Output - 
// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 
