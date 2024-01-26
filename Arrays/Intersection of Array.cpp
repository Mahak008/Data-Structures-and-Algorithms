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

// Optimized Approach

vector <int> v1{1, 2, 3, 4, 40};
vector <int> v2{ 3, 4, 4, 8};
vector <int> ans;
unsigned i = 0, j = 0;

while(i < v1.size() && j < v2.size()) {
    if(v1[i] < v2[j]) {
      i++;
    }

    else if(v1[i] == v2[j]) {
      ans.push_back(v1[i]);
      i++;
      j++;
    }

    else {
        j++;
    }
}
for(auto it : ans) {
    cout << it << endl;
}

// Output -
// 1
// 2
// 3
// 4
// 4
