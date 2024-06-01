class MyQueue {
public:
  stack<int> s1, s2;
  
  void push(int x) {
    s1.push(x); 
  }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int x = s2.top();
    s2.pop();
    return x;
  }

  int peek() {
    if (s2.empty()) {
      // Transfer all elements from s1 to s2
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty() { 
    return s1.empty() && s2.empty();
  }
};

int main() {
  MyQueue *obj = new MyQueue();

  obj->push(1);
  obj->push(2);
  obj->push(3);

  cout << "Popped element: " << obj->pop() << endl; 
  cout << "Front element: " << obj->peek() << endl; 
  cout << "Is the queue empty? " << (obj->empty() ? "Yes" : "No")<< endl; 
  delete obj;

  return 0;
}

