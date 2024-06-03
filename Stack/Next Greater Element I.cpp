// Using Array
// Time - O(n * m)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  vector<int>temp(nums2.size(), -1);
  for(int i = 0; i < nums2.size(); i++) {
    for(int j = i+1; j < nums2.size(); j++) {
      if(nums2[j] > nums2[i]) {
        temp[i] = nums2[j];
        break;
      }
    }
  }

  for(int i = 0; i < nums1.size();i++) {
    auto it = find(nums2.begin(), nums2.end(), nums1[i]);
    if (it != nums2.end())  {  
      int index = it - nums2.begin();
      nums1[i] = temp[index]; 
    } 
    else { 
      nums1[i] = -1;
    }     
  }
  return nums1;
}

// Using Stack
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  stack <int> st;
  unordered_map<int, int> m;
  for(int i = 0; i < nums2.size(); i++) {
    while(!st.empty() && st.top() < nums2[i]) {
      m[st.top()] = nums2[i];
      st.pop();
    }
    st.push(nums2[i]);
  }
    
  vector<int>ans;
  for (int num : nums1) {
    ans.push_back(m.count(num) ? m[num] : -1);
      // OR
    auto it = m.find(num);
    ans.push_back(it != m.end() ? it -> second : -1);
  }
  return ans;
}

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
