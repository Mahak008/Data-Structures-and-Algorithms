class Node{
  public:
    Node* prev;
    int data;
    Node* next;
 
    Node() { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value) { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node * head = new Node(arr[0]) ;
        Node *temp = head;
      
        for(int i = 1; i < arr.size(); i++) {
            Node * n = new Node(arr[i]);
            temp -> next = n;
            n -> prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};
