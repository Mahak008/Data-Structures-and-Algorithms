//Function to find all elements in array that appear more than N = n/k times.

int countOccurence(int arr[], int n, int k) {
  map <int,int> m;
        
  for(int i=0;i<n;i++) {
    m[arr[i]]++;
  }
            
  int count=0;
        
  for(auto it: m){
    if(it.second>(n/k))
      count++;
    }
    return count;
  }
}

// Input:
// N = 8
// arr[] = {3,1,2,2,1,2,3,3}
// k = 4

// Output: 2

// Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times.
