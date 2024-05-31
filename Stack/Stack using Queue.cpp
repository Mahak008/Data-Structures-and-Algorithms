class MyStack {
public:
    MyStack() {
    }
    queue <int> q1, q2;
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }   
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }  
    }
    
    int pop() {
        int m = q1.front();
        q1.pop();
        return m;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Alternate push function
void push(int x) {
  q2.push(x);  
  while (!q1.empty()) {
    q2.push(q1.front());
    q1.pop();
  }
  swap(q1, q2);
}
