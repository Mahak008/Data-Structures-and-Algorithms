while(start <= end) {
  int temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  start++;
  end--;
}

// Input - 1 2 3 4 5
// Output - 5 4 3 2 1
