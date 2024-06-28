long long toh(int n, int from, int to, int aux) {
  if(n == 1) {
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    return 1;
  }
  
  long long x1 = toh(n-1,from,aux,to);
  cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
  long long x2 = toh(n-1,aux,to,from);
        
  return 1 + x1 + x2;
}

// Input: n = 3
  
// Output:
// move disk 1 from rod 1 to rod 3
// move disk 2 from rod 1 to rod 2
// move disk 1 from rod 3 to rod 2
// move disk 3 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 1
// move disk 2 from rod 2 to rod 3
// move disk 1 from rod 1 to rod 3

// Total Moves: 7
