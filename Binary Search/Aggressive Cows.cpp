bool place(vector<int> &stalls, int dist, int k) {
    int cows = 1, last = stalls[0];
    
    for(int i = 1; i < stalls.size(); i++) {
        if((stalls[i] - last) >= dist) {
            cows++;
            last = stalls[i];
        }
    }
    
    if(cows >= k) {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());
    
  int low = 0, high = stalls[stalls.size()-1] - stalls[0];
    
  while(low <= high) {
    int mid = (low + high)/2;
    bool x = place(stalls, mid, k) ;
      
    if(x) {
        low = mid + 1;
    }
    else {
        high = mid - 1;
    }
  }
  return high;
}

// Input: cows - 4, dist - 0 3 4 7 10 9
// Output: 3
