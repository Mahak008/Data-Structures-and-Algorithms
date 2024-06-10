class Deque {
private:
    int arr[100005];  // array to store elements
    int front;        // front index
    int rear;         // rear index
    int size;         // maximum size of the deque

public:
    Deque(int n = 100005) {
        size = n;
        front = -1;
        rear = -1;
    }

    // Function to check if the deque is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front == rear + 1));
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to insert an element at the front of the deque
    void insertFront(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (front == -1) { // First element insertion
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1; // Circular deque
        } else {
            front = front - 1;
        }
        arr[front] = x;
    }

    // Function to insert an element at the rear of the deque
    void insertRear(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }

        if (rear == -1) { // First element insertion
            front = 0;
            rear = 0;
        } else if (rear == size - 1) {
            rear = 0; // Circular deque
        } else {
            rear = rear + 1;
        }
        arr[rear] = x;
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) { // Only one element
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0; // Circular deque
        } else {
            front = front + 1;
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (front == rear) { // Only one element
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = size - 1; // Circular deque
        } else {
            rear = rear - 1;
        }
    }

    // Function to get the front element of the deque
    int getFront() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front];
    }

    // Function to get the rear element of the deque
    int getRear() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(5);
    dq.insertRear(10);
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "Rear element after deletion: " << dq.getRear() << endl;

    dq.insertFront(15);
    dq.insertFront(20);
    cout << "Front element: " << dq.getFront() << endl;

    dq.deleteFront();
    cout << "Front element after deletion: " << dq.getFront() << endl;

    return 0;
}

