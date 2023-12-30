// Change bit from 0 to 1
int n = 5, k = 2;
int n1 = 1 << (k-1); // 010
n = n1 | n ;
cout<< n;

// Output - 7

// Change bit from 1 to 0
int n = 5, k = 1;
int n1 = ~(1 << (k-1)); // 100
n = n1 & n ;
cout<< n;

// Output - 4 
