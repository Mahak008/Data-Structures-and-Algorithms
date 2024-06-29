// Inductive Base Hypothesis

int solve(int n, int k) {
    // Base case: when only one person is left
    if (n == 1) {
        return 0; // The position is 0 (0-based index)
    } else {
        // The position returned by findTheWinner(n - 1, k) is adjusted
        // because the recursive call findTheWinner(n - 1, k) considers the
        // original problem as if the person at position k % n is killed
        return (solve(n - 1, k) + k) % n;
    }
}

// This function converts the 0-based index to a 1-based index
int findTheWinner(int n, int k) { 
  return solve(n, k) + 1; 
}

// Input: n = 5, k = 2
// Output: 3
  
// Explanation: Here are the steps of the game:
// 1) Start at friend 1.
// 2) Count 2 friends clockwise, which are friends 1 and 2.
// 3) Friend 2 leaves the circle. Next start is friend 3.
// 4) Count 2 friends clockwise, which are friends 3 and 4.
// 5) Friend 4 leaves the circle. Next start is friend 5.
// 6) Count 2 friends clockwise, which are friends 5 and 1.
// 7) Friend 1 leaves the circle. Next start is friend 3.
// 8) Count 2 friends clockwise, which are friends 3 and 5.
// 9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
