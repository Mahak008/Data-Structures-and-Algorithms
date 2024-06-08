class MyCircularQueue {
    vector<int> cq;
    int front;
    int rear;
    int count;
    int capacity;

public:

    MyCircularQueue(int k) {
        capacity = k;
        cq.resize(capacity);
        front = 0;
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        } 
        rear = (rear + 1) % capacity;
        cq[rear] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return cq[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return cq[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
     return count == capacity;   
    }
};
