class Node {
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // If first node is to be deleted
        if(x == 1) {
            Node *del = head;
            head = head -> next;
            head -> prev = NULL;
            delete del;
            return head;
        }
        
        int cnt = 1;
        Node*temp = head;
        
        while(cnt < x-1 && temp -> next != NULL) {
            cnt++;
            temp = temp -> next;
        }
        
        // If last node is to be deleted
        if(temp -> next -> next == NULL) {
            Node *del = temp -> next -> next;
            temp -> next = NULL;
            delete del;
            return head;
        }
        
        // If node at any other position is to be delted
        Node *del = temp -> next;
        temp -> next = del -> next;
        temp -> next -> prev = temp;

        delete del;
        return head;
    }
};
