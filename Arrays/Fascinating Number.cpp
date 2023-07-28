// Fascinating No. - When a number(should contain 3 digits or more) is multiplied by 2 and 3, and when both these products are concatenated with the original number, then it results in all digits from 1 to 9 present exactly once.

bool fascinating(int n) {
  long two = n*2; // Multiply no. by 2
  long three = n*3; // Multiply no. by 3
        
  string s1 = to_string(n); // convert original no. to string
  string s2 = to_string(two); // convert no. multiplied with 2 to string
  string s3 = to_string(three); // convert multiplied with 3 to string
        
  string s = s1 + s2 + s3; // concat all the strings
    
  string str = "123456789";
  sort(s.begin(), s.end());
        
  if(str == s) {
    return true;
  }
  else {
    return false;
  }
}
