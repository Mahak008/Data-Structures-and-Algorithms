// Algorithm 
// 1. If the symbol is an operand, Push it onto the stack. 
// 2. If the symbol is an operator, Pop the top 2 values from the stack. 
// 3. Put the operator, with the values as arguments and form a string. 
// 4. Push the resulted string back to stack. 
// 5. If there is only one value in the stack, that value in the stack is the desired infix string. 


bool isOperand(char x) {
  return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

string getInfix(string exp) {
  stack<string> s;

  for (int i = 0; exp[i] != '\0'; i++) {
    // Push operands
    if (isOperand(exp[i])) {
      string op(1, exp[i]);
      s.push(op);
    }

    else {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      s.push("(" + op2 + exp[i] + op1 + ")");
    }
  }
  
  return s.top();
}

// Driver code
int main() {
  string exp = "ab*c+";
  cout << getInfix(exp);
  return 0;
}

// OUTPUT: ((a*b)+c)
