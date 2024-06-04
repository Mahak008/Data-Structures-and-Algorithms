//Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n){
  vector<long long> v;
  stack <long long> st;
        
  for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && st.top () <= arr[i]) {
      st.pop();
    }
    if(st.empty()) {
      v.push_back(-1);
    }
    else {
      v.push_back(st.top());
    }
    st.push(arr[i]);
  }
  reverse(v.begin(), v.end());
  return v;
}

// Input: 6 8 0 1 3
// Output: 8 -1 1 3 -1        
