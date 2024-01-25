int a[] = {34, 45, 1, 23, 90, 110, 76, 54, 99, 86};
int max = INT_MIN;
int res = INT_MIN;
for(int i = 0; i < 10; i++) {
    if(a[i] > max) {
        res = max;
        max = a[i];
    }
    else if (a[i] > res && a[i] != max) {
        res = a[i];
    }
}
cout << res;

// Output - 99
