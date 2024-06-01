// ALgorithm
// 1. If operand, Push it to Stack
// 2. If operator, Pop two elements from the Stack. 
// 3. Operate on these elements according to the operator.
// 4. Put the result back to the stack.


int evaluatePrefix(string S) {
  stack<int> s;
  int len = S.length();
  for (int i = len - 1; i >= 0; i--) {
    if (isdigit(S[i])) {
      s.push(S[i] - '0');
    } else {
      int op1 = s.top();
      s.pop();
      int op2 = s.top();
      s.pop();
      switch (S[i]) {
      case '+':
        s.push(op1 + op2);
        break;
      case '-':
        s.push(op1 - op2);
        break;
      case '*':
        s.push(op1 * op2);
        break;
      case '/':
        s.push(op1 / op2);
        break;
      case '%':
        s.push(op1 % op2);
        break;
      case '^':
        s.push(pow(op1, op2));
        break;
      }
    }
  }
  return s.top();
}
