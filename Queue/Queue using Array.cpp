class QueueNode {
public:
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue() {
        front = 0;
        rear = 0;
    }
    void push(int x);
    int pop();
};

// Function to push an element x in a queue.
void MyQueue::push(int x) {
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue::pop() {
    if (front == rear) { // If the queue is empty
        return -1;
    }
    return arr[front++];
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

