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
