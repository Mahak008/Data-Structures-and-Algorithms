// Numbers Spaces Numbers
int n = 4, i, j;
int spaces = 2 * (n-1);
    
for(i = 1; i <= n; i++){
  // for numbers
  for(j = 1; j <= i; j++) {
    cout << j;
  }
        
  // for Spaces
  for(j = 1; j <= spaces; j++) {
    cout << "*";
  }
        
  // for numbers
  for(j = i; j >= 1; j--) {
    cout << j;
  }
        
  cout << endl;
  spaces -= 2;
}

// Output - 
// 1******1
// 12****21
// 123**321
// 12344321
