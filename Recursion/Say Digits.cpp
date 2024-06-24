void sayDigit(int n, string arr[]) {
  if(n == 0) {
    return;
  }
  int digit = n % 10;
  n /= 10;

  sayDigit(n, arr);
  cout << arr[digit] << " ";
}

int main() {
  string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"}; 
  int n;
  cin >> n;
  
  sayDigit(n, arr);
  return 0;
}

// Input: 412
// Output: four one two
