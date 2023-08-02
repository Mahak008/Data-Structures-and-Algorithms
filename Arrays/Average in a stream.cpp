vector<float> streamAvg(int arr[], int n) {
  vector <float> v;
  float ans = 0, avg = 0;
    
  for(int i = 0; i < n; i++) {
    ans += arr[i];
    avg = ans/(i+1);
    v.push_back(avg);
  }
  return v;
}

// Input:
// n = 5
// arr[] = {10, 20, 30, 40, 50}

// Output: 10.00 15.00 20.00 25.00 30.00 

// Explanation: 
// 10 / 1 = 10.00
// (10 + 20) / 2 = 15.00
// (10 + 20 + 30) / 3 = 20.00
// And so on.
