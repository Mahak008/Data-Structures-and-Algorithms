class HistoryNode {
public:
    string data;
    HistoryNode* prev;
    HistoryNode* next;

    HistoryNode(string x) : data(x), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
public:
    HistoryNode* curr;

    BrowserHistory(string homepage) { 
        curr = new HistoryNode(homepage); 
    }

    void visit(string url) {
        HistoryNode* newNode = new HistoryNode(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    string back(int steps) {
        while(steps > 0 && curr->prev) {
            curr = curr->prev;
            steps--;
        }
        return curr->data;
    }

    string forward(int steps) {
        while(steps > 0 && curr->next) {
            curr = curr->next;
            steps--;
        }
        return curr->data;
    }
};
