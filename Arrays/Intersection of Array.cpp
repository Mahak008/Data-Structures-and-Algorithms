vector <int> ans;
for(int i = 0; i < arr1.size(); i++) {
  int ele = arr1[i];
  for(int j = 0; j < arr2.size(); j++) {
    if(ele < arr2[j]) {
      break;
    }

    if(arr2[j] == ele) {
      ans.push_back(ele);
      arr2[j] == INT_MIN;
      break;
    }
  }
}
