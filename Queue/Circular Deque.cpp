class MyCircularDeque {
private:
    vector<int> cdq;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor: Initializes the deque with a maximum size of k
    MyCircularDeque(int k) { 
      capacity = k;
      cdq.resize(capacity);
      front = 0;
      rear = 0;
      size = 0;  
    }

    // Insert an item at the front of Deque
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        cdq[front] = value;
        size++;
        return true;
    }

    // Insert an item at the rear of Deque
    bool insertLast(int value) {
        if (isFull()) return false;
        cdq[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    // Delete an item from the front of Deque
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    // Delete an item from the rear of Deque
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    // Get the front item from the Deque
    int getFront() {
        if (isEmpty()) return -1;
        return cdq[front];
    }

    // Get the last item from Deque
    int getRear() {
        if (isEmpty()) return -1;
        return cdq[(rear - 1 + capacity) % capacity];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }
};

