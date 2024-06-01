// Algorithm
// 1. Read the Postfix expression from left to right
// 2. If the symbol is an operand, then push it onto the Stack
// 3. If the symbol is an operator, then pop two operands from the Stack 
// 4. Create a string by concatenating the two operands and the operator before them, string = operator + operand2 + operand1 
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

string postToPre(string post_exp) {
  stack<string> s;
  int len = post_exp.length();

  for (int i = 0; i < len; i++) {
    if (!isOperator(post_exp[i])) {
      s.push(string(1, post_exp[i]));
    } else {
      string s1 = s.top();
      s.pop();
      string s2 = s.top();
      s.pop();

      string ans = post_exp[i] + s2 + s1;
      s.push(ans);
    }
  }
  return s.top();
}

// Driver Code
int main() {
  string pre_exp = "ABC/-AK/L-*";
  cout << "Postfix : " << postToPre(pre_exp);
  return 0;
}

// OUTPUT:
// Prefix : *-A/BC-/AKL
  
