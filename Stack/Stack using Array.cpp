// A Stack is a linear data structure that follows  LIFO(Last In First Out) or FILO(First In Last Out). 
// Applications:
// Recursion
// Expression Evaluation and Parsing
// Depth-First Search (DFS)
// Undo/Redo Operations
// Browser History
// Function Calls

class MyStack {
  private:
    int arr[1000];
    int top;
  public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

//Function to add an item at the top of the stack.
void MyStack :: push(int x) {
    // Overflow
    if(top == arr.size() {
        cout <<"Overflow";
    }
    top++;
    arr[top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop() {
    // Underflow
    if(top == -1) {
        return -1;
    }
    int x = arr[top];
    --top;
    return x;
}
