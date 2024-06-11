string FirstNonRepeating(string A){
  unordered_map<char, int> mp;
  queue<char> q;
  string ans = "";
	
  for(int i = 0; i < A.length(); i++) {
  	mp[A[i]]++;
	q.push(A[i]);
		    
	while(!q.empty() && mp[q.front()] > 1) {
	  q.pop();
	}	
		
    	if(q.empty()) {
	  ans += '#';
	}
	else {
	  ans += q.front();
	}    
    }
    return ans;
}

// Input: "aabc"
// Output: "a#bb"
