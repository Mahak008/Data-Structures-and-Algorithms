// Algorithm
// 1. If the element is a number, push it into the stack.
// 2. If the element is an operator, pop operands for the operator from the stack. 
// 3. Evaluate the operator and push the result back to the stack.
// 4. When the expression is ended, the number in the stack is the final answer.

int evaluatePostfix(string S) {
  stack<int> s;
  int len = S.length();
  
  for (int i = 0; i < len; i++) {
    if (isdigit(S[i])) {
      s.push(S[i] - '0');
    } 
    else {
      int op1 = s.top();
      s.pop();
      int op2 = s.top();
      s.pop();
      
      switch (S[i]) {
      case '+':
        s.push(op2 + op1);
        break;
      case '-':
        s.push(op2 - op1);
        break;
      case '*':
        s.push(op2 * op1);
        break;
      case '/':
        s.push(op2 / op1);
        break;
      case '%':
        s.push(op2 % op1);
        break;
      case '^':
        s.push(pow(op2, op1));
        break;
      }
    }
  }
  return s.top();
}

int main() {
  string exp = "2+3*1-9^2";
  cout << ob.evaluatePostfix(s1) << endl;
  return 0;
}

// OUTPUT: -76
