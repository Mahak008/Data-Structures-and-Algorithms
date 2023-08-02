int PalinArray(int a[], int n) {
  for(int i = 0; i < n; i++) {
    int sum = 0;
    int num = a[i];
    	    
    while(a[i]) {
      sum = sum * 10 + a[i] % 10;
    	a[i] = a[i] / 10;
    }
    	    
    if(num != sum) {
    	return 0;
    }
  }
  return 1;
}

// Input:
// 5
// 111 222 333 444 555

// Output:
// 1

// Explanation:
// A[0] = 111 //which is a palindrome number.
// A[1] = 222 //which is a palindrome number.
// A[2] = 333 //which is a palindrome number.
// A[3] = 444 //which is a palindrome number.
// A[4] = 555 //which is a palindrome number.
// As all numbers are palindrome so This will return 1.
