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
    cout << it << " ";
}

// Output -
// 3 4
