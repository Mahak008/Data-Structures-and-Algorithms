class MyCircularDeque {
private:
    vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor: Initializes the deque with a maximum size of k
    MyCircularDeque(int k) { 
      int data[k]; 
      int front(0), 
      int rear(0), 
      int size(0), 
      int capacity(k) 
    }

    // Insert an item at the front of Deque
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        size++;
        return true;
    }

    // Insert an item at the rear of Deque
    bool insertLast(int value) {
        if (isFull()) return false;
        data[rear] = value;
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
        return data[front];
    }

    // Get the last item from Deque
    int getRear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + capacity) % capacity];
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

