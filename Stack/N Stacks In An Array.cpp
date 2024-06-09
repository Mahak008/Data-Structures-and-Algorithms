// 1st Approach - Divide Array into k sub parts for N stacks of length k
// Drawbacks - No Space Optimization

#include <bits/stdc++.h>
class NStack {
    int *arr,*top, *next;
    int n, s;
    int freeSpot;
public:

  NStack(int N, int S) {
    n = N; // The number of stacks. This is the number of individual stacks that you want to manage within a single array.
    s = S; // The size of the array that holds all the elements across all stacks. This is the total capacity for storing elements in all stacks combined.
    arr = new int[s]; // An array of size s that holds all the elements of the stacks.
    top = new int[n]; // An array of size n that keeps track of the top element index for each stack.
    next = new int[s]; // An array of size s that helps in managing free slots and links to the next element in the stack.

    // Initialize top
    for(int i = 0; i < n; i++) {
      top[i] = -1;
    }

    // Initialize Next
    for(int i = 0; i < s; i++) {
      next[i] = i+1;
    }

    // Update Last index value to -1
    next[s-1] = -1;

    // Initialize freeSpot
    freeSpot = 0;
  }

  // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the
  // stack, and false otherwise.
  bool push(int x, int m) {
    // Check Overflow
    if(freeSpot == -1) {
      return false;
    }
    // Find Index
    int index = freeSpot;
    
    // Update freeSpot
    freeSpot = next[index];

    // Insert element into array
    arr[index] = x;

    // Update next;
    next[index] = top[m-1];

    // Update Top
    top[m-1] = index;

    return true;
  }

  // Pops top element from Mth Stack. Returns -1 if the stack is empty,
  // otherwise returns the popped element.
  int pop(int m) {
    // Check underflow
    if(top[m-1] == -1) {
      return -1;
    }

    int index = top[m-1];

    top[m-1] = next[index];

    next[index] = freeSpot;

    freeSpot = index;

    return arr[index];
  }
};
