// Algorithm
// 1. Read the Prefix expression in reverse order (from right to left)
// 2. If the symbol is an operand, then push it onto the Stack
// 3. If the symbol is an operator, then pop two operands from the Stack 
// 4. Create a string by concatenating the two operands and the operator between them, string = (operand1 + operator + operand2) 
// 5. Push the resultant string back to Stack


class Solution {
public:
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

  string postToInfix(string exp) {
    // Write your code here
    stack<string> s;

    // length of expression
    int length = exp.size();

    // reading from right to left
    for (int i = 0; i < length; i++) {

      // check if symbol is operator
      if (isOperator(exp[i])) {

        // pop two operands from stack
        string op1 = s.top();
        s.pop();
        string op2 = s.top();
        s.pop();

        // concat the operands and operator
        string temp = "(" + op1 + exp[i] + op2 + ")";

        // Push string temp back to stack
        s.push(temp);
      }

      // if symbol is an operand
      else {

        // push the operand to the stack
        s.push(string(1, exp[i])); // here it is a stack of strings, so we have
                                   // to convert the character to string.
        // string(1, pre_exp[i]), the 1 specifies the number of times the
        // character pre_exp[i] should be repeated in the new string being
        // created.
      }
    }

    // Stack now contains the Infix expression
    return s.top();
  }
};

// Driver Code
int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "Infix : " << preToInfix(pre_exp);
  return 0;
}

// OUTPUT:
// Infix : ((A-(B/C))*((A/K)-L))
  
