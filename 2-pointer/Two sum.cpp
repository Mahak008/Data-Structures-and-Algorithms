string read(int n, vector<int> book, int target) {
  sort(book.begin(), book.end());
  int i = 0, j = n-1;
  while(i <= j) {
    int sum = book[i] + book[j];
    if(sum == target) {
      return "YES";
    }
    if(sum < target) {
      i++;
    }
    else {
      j--;
    }
  }
  return "NO";
}

// TARGET = 5
// BOOK = 4, 1, 2, 3, 1 

// Not applicable if we have to find the index of no whose sum is equal to target.
