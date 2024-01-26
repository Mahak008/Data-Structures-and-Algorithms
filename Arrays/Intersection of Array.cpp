vector <int> v1{1, 2, 3, 4, 4};
vector <int> v2{1, 2, 2, 3, 4, 4, 8};
vector <int> ans;

for(unsigned i = 0; i < v1.size(); i++) {
  
  int ele = v1[i];

  for(unsigned j = 0; j < v2.size(); j++) {
    if(ele < v2[j]) {
      break;
    }

    if(v2[j] == ele) {
      ans.push_back(ele);
      v1[i] = INT_MIN;
      break;
    }
  }
}
for(auto i : ans) {
    cout << i << endl;
}

// Output -
// 1
// 2
// 3
// 4
// 4
