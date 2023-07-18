// Function returns the second
// largest elements

int print2largest(int arr[], int n) {
  set <int> s;
	for(int i = 0; i < n; i++) {
	  s.insert(arr[i]);
	}
	    
  auto it = s.begin();
	int l = s.size();
        
  for(int i = 0; i < l-2; i++) {
    it++;
  }
  int ans = *it;
  if(s.size() == 1) {
    return -1;
  }
  return ans;
}
