// Leetcode - 208

class Node {
public:
    Node* links[26];
    bool flag = false;

    Node() {
        // Initialize all links to nullptr
        for (int i = 0; i < 26; ++i) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) { 
        return links[ch - 'a'] != nullptr; 
    }

    void put(char ch, Node* node) { 
        links[ch - 'a'] = node; 
    }

    Node* get(char ch) { 
        return links[ch - 'a']; 
    }

    void setEnd() { 
        flag = true; 
    }

    bool isEnd() { 
        return flag; 
    }
};

class Trie {
public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }

    ~Trie() {
        // Properly delete the Trie to avoid memory leaks
        deleteNodes(root);
    }

private:
    Node* root;

    void deleteNodes(Node* node) {
        if (!node)
            return;

        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                deleteNodes(node->links[i]);
            }
        }

        delete node;
    }
};


// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]

// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
 
