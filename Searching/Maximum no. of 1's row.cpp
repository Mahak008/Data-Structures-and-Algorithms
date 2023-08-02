int maxOnes (vector <vector <int>> &Mat, int N, int M) {
  int max = INT_MIN, x;
  for(int i = 0; i < N; i++) {
    int count = 0;
        
    for(int j = 0; j < M; j++) {
      if(Mat[i][j] == 1) {
        count++;
      }
    }
                
    if(count > max) {
      max = count;
      x = i;
    }
  }
  return x;
}

// N = 3, M = 4
// Mat[] = {{0 1 1 1},
//          {0 0 1 1},
//          {0 0 1 1}}

// Output: 0

// Explanation: Row 0 has 3 ones whereas rows 1 and 2 have just 2 ones.
