bool kPangram(string str, int k) {
  int size = 0;
        
  vector<bool> chc(26,false);
        
  for(auto i: str){
    if(i == ' '){
      continue;
    }
    chc[i-'a'] = true;
    size++;
  }
        
  if(size < 26) 
    return false;
        
  for(bool c:chc){
    if(c == false){
      k--;
    }
  }
  
  return k >= 0;
}

// Input: str = "a b c d e f g h i j k l m", k = 20
// Output: false
