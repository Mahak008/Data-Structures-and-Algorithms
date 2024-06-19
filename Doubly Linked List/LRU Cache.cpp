class LRUCache {
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    unordered_map<int, Node*> mp; // hash map to store key and corresponding node
    int quantity; // maximum capacity of the cache
    Node* head; // pointer to the head of the doubly linked list
    Node* tail; // pointer to the tail of the doubly linked list

    void removeNode(Node* node) {
        if (node->prev)
            node->prev->next = node->next;
        
        if (node->next)
            node->next->prev = node->prev;
        
        if (node == head)
            head = node->next;
        
        if (node == tail)
            tail = node->prev;
    }

    void addToFront(Node* node) {
        node->next = head;
        node->prev = NULL;
        
        if (head)
            head->prev = node;
        
        head = node;
        
        if (!tail)
            tail = head;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        quantity = capacity;
        head = NULL;
        tail = NULL;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            moveToFront(node);
            return node->value;
        }
        return -1; // key not found
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToFront(node);
        } 
        else {
            Node* newNode = new Node(key, value);
            
            if (mp.size() == quantity) {
                mp.erase(tail->key);
                Node* oldTail = tail;
                removeNode(oldTail);
                delete oldTail;
            }
            
            addToFront(newNode);
            mp[key] = newNode;
        }
    }
};

// Input:
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

// Output:
// [null, null, null, 1, null, -1, null, -1, 3, 4]
