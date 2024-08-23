int maxMeetings(int n, int start[], int end[]) {
  vector<pair<int, int>> v;
  
  for(int i = 0; i < n; i++) {
    v.push_back(make_pair(end[i], start[i]));
  }
        
  sort(v.begin(), v.end());
        
  int ans = 0; 
  int prev_end = -1;
        
  for(int i = 0; i < n; i++) {
    int cur_start = v[i].second;
    int cur_end = v[i].first;
            
    if(cur_start > prev_end) {
      ans++;
      prev_end = cur_end;
    }
  }
        
  return ans;
}

// Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
