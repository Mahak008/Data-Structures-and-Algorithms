// Last element of the queue is connected to the first element of the queue forming a circle.
// The operations are performed based on FIFO (First In First Out) principle. It is also called ‘Ring Buffer’.
// One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

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
