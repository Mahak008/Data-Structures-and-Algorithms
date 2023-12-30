int n = 5, i, j;
for(i = 0; i < n; i++) {
  for(j = 0; j < (n-i); j++) {
    cout << " ";
  }
        
  char ch = 'A';
  int breakpoint = (2*i)/2;
  for(j = 1; j <= 2*i+1; j++) {
    if(j <= breakpoint) {
      cout << ch++;
    }
    else {
      cout << ch--;
    }
  }
  cout << endl;
}

// Output - 
//      A
//     ABA
//    ABCBA
//   ABCDCBA
//  ABCDEDCBA
