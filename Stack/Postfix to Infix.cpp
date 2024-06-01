// Algorithm 
// 1. If the symbol is an operand, Push it onto the stack. 
// 2. If the symbol is an operator, Pop the top 2 values from the stack. 
// 3. Put the operator, with the values as arguments and form a string. 
// 4. Push the resulted string back to stack. 
// 5. If there is only one value in the stack, that value in the stack is the desired infix string. 


bool isOperand(char x) {
  return isalpha(x) || isdigit(x);
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

// Alternate Method
// function to check if character is operator or not
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

string postToInfix(string pre_exp) {
  stack<string> s;
  int length = pre_exp.size();

  for (int i = 0; i < length; i++) {

    // check if symbol is operator
    if (isOperator(pre_exp[i])) {

      // pop two operands from stack
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();

      // concat the operands and operator in reverse order
      string temp = "(" + op2 + pre_exp[i] + op1 + ")";

      // Push string temp back to stack
      s.push(temp);
    }

    // if symbol is an operand
    else {
      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }

  // Stack now contains the Postfix expression
  return s.top();
}

// Driver Code
int main() {
  string pre_exp = "ab*c+";
  cout << "Postfix : " << postToInfix(pre_exp);
  return 0;
}


// OUTPUT: ((a*b)+c)
