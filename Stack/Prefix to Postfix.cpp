// Algorithm
// 1. Read the Prefix expression in reverse order (from right to left)
// 2. If the symbol is an operand, then push it onto the Stack
// 3. If the symbol is an operator, then pop two operands from the Stack 
// 4. Create a string by concatenating the two operands and the operator after them, string = operand1 + operand2 + operator 
// 5. Push the resultant string back to Stack


bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
  case '^':
  case '%':
    return true;
  }
  return false;
}
string preToPost(string pre_exp) {
  stack<string> s;
  int len = pre_exp.length();

  for (int i = len - 1; i >= 0; i--) {
    if (!isOperator(pre_exp[i])) {
      s.push(string(1, pre_exp[i]));
    } else {
      string s1 = s.top();
      s.pop();
      string s2 = s.top();
      s.pop();

      string ans = s1 + s2 + pre_exp[i];
      s.push(ans);
    }
  }
  return s.top();
}

int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "Prefix : " << preToPost(pre_exp);
  return 0;
}

// Output:  ABC/-AK/L-*
