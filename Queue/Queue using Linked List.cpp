class QueueNode {
public:
  int data;
  QueueNode *next;
  QueueNode(int a) {
    data = a;
    next = NULL;
  }
};

class MyQueue {
public:
  QueueNode *front;
  QueueNode *rear;
  MyQueue() { 
    front = rear = NULL; 
  }
  void push(int x);
  int pop();
};

// Function to push an element into the queue.
void MyQueue::push(int x) {
  QueueNode *temp = new QueueNode(x);
  if (rear == NULL) { // If the queue is empty
    front = rear = temp;
  } 
  else {
    rear->next = temp;
    rear = temp;
  }
}

// Function to pop front element from the queue.
int MyQueue::pop() {
  if (front == NULL) { // If the queue is empty
    return -1;
  }
  
  int x = front->data;
  QueueNode *temp = front;
  front = front->next;
  
  if (front == NULL) { // If the queue becomes empty
    rear = NULL;
  }
  delete temp;
  return x;
}

int main() {
  MyQueue queue;

  queue.push(10);
  queue.push(20);
  cout << queue.pop() << endl; // Should print 10
  queue.push(30);
  queue.push(40);
  cout << queue.pop() << endl; // Should print 20
  cout << queue.pop() << endl; // Should print 30
  cout << queue.pop() << endl; // Should print 40
  cout << queue.pop() << endl; // Should print -1 since the queue is empty

  return 0;
}

