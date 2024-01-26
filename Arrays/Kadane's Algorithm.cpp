int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
int n = sizeof(a) / sizeof(a[0]);
int maxSum = INT_MIN, curSum = 0, start = 0, end = 0, s = 0;
 
for (int i = 0; i < n; i++) {
    curSum += a[i];
 
    if (curSum > maxSum) {
        maxSum = curSum;
        start = s;
        end = i;
    }
 
    if (curSum < 0) {
        curSum = 0;
        s = i + 1;
    }
}
cout << "Maximum contiguous sum : " << maxSum << endl;
cout << "Starting index : " << start << endl;
cout << "Ending index : " << end << endl;

// Output -
// Maximum contiguous sum : 7
// Starting index : 2
// Ending index : 6
