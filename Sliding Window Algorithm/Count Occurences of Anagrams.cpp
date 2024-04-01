int search(string pat, string txt) {
  int count = 0;
  int patLen = pat.length();
  int txtLen = txt.length();

  for (int i = 0; i <= txtLen - patLen; i++) {
    string sub = txt.substr(i, patLen);
    sort(sub.begin(), sub.end()); 
    if (sub == pat) { 
      ++count;
    }
  }
	return count;
}
