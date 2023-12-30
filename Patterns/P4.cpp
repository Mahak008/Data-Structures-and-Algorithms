int n = 5, i, j, spaces = 0;
for(i = 0; i < n; i++) {

  // stars
  for(j = 0; j < n-i; j++) {
    cout << "*";
  }
        
  // spaces
  for(j = 0; j < spaces; j++) {
    cout << " ";
  }

  // stars
  for(j = 0; j < n-i; j++) {
    cout << "*";
  }
  spaces += 2;
  cout << endl;
}

spaces = 2*n-2;
for(i = 0; i < n; i++) {

  // stars
  for(j = 0; j <= i; j++) {
    cout << "*";
  }
        
  // spaces
  for(j = 0; j < spaces; j++) {
    cout << " ";
  }

  // stars
  for(j = 0; j <= i; j++) {
    cout << "*";
  }
  spaces -= 2;
  cout << endl;
}

// Output - 
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
