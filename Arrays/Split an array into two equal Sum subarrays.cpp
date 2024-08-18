bool canSplit(vector<int>& arr) {
  int n = arr.size();
        
  if(n < 2) {
    return false;
  }
        
  int i = 0, j = n-1;
  int sum1 = arr[i], sum2 = arr[j];
        
  while(i < j) {
    if(sum1 < sum2) {
      i++;          
      if (i < n) { // Make sure we don't go out of bounds
        sum1 += arr[i];
      }
    } else if(sum2 < sum1) {
      j--;
      if (j >= 0) {
        sum2 += arr[j];
      }
    }  else {
      if (i >= j - 1) { // Make sure we have at least one element on each side
        return true;
      }        
      i++;
      j--;
                
      if (i < n) { // Make sure we don't go out of bounds
        sum1 += arr[i];
      }
            
      if (j >= 0) { // Make sure we don't go out of bounds
        sum2 += arr[j];
      }
    }
  }
  return false;
}

// Input: arr = [1, 2, 3, 4, 5, 5]
// Output: true
// Explanation: In the above example, we can divide the array into two subarrays with eqaul sum. The two subarrays are: [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10. Hence, the answer is true.
