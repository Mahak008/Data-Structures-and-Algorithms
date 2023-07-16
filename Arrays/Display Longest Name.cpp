string longest(string names[], int n) {
  int len = -1, l;
  string s;
  for (int i = 0; i < n; i++) {
    l = names[i].length();
    if(l > len) {
      len = l;
      s = names[i];
    }
  }
  return s;
}
