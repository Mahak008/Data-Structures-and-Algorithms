#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack() { 
        top = NULL; 
    }
};

void MyStack::push(int x) {
    StackNode* newNode = new StackNode(x);
    if(top == NULL) {
        top = newNode;
    }
    else {
        newNode->next = top;
        top = newNode;
    }
}

int MyStack::pop() {
    if(top == NULL) return -1;
    
    int ans = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp; // Free memory of the popped node
    return ans;
}

int main() {
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Popped element: " << stack.pop() << endl; // Output: 30
    cout << "Popped element: " << stack.pop() << endl; // Output: 20
    cout << "Popped element: " << stack.pop() << endl; // Output: 10
    cout << "Popped element: " << stack.pop() << endl; // Output: -1 (stack is empty)

    return 0;
}
