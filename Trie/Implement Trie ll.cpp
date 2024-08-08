class Node {
public:
  Node *links[26];
  int cntEndWith = 0; // Counter for number of words that end at this node
  int cntPrefix =
      0; // Counter for number of words that have this node as a prefix

  Node() {
    // Initialize all links to nullptr
    for (int i = 0; i < 26; ++i) {
      links[i] = NULL;
    }
  }

  // Function to check if the node contains a specific key
  bool containsKey(char ch) {
    // Check if the link corresponding to the character exists
    return (links[ch - 'a'] != NULL);
  }

  // Function to get the child node corresponding to a key
  Node *get(char ch) {
    // Return the link corresponding to the character
    return links[ch - 'a'];
  }

  // Function to insert a child node with a specific key
  void put(char ch, Node *node) {
    // Set the link corresponding to the character to the provided node
    links[ch - 'a'] = node;
  }

  // Function to increment the count of words that have this node as a prefix
  void increasePrefix() {
    // Increment the counter
    cntPrefix++;
  }

  // Function to decrement the count of words that have this node as a prefix
  void reducePrefix() {
    // Decrement the counter
    cntPrefix--;
  }

  // Function to increment the count of words that end at this node
  void increaseEnd() {
    // Increment the counter
    cntEndWith++;
  }

  // Function to decrement the count of words that end at this node
  void deleteEnd() {
    // Decrement the counter
    cntEndWith--;
  }
};

class Trie {
private:
  Node *root;

public:
  Trie() {
    // Create a new root node
    root = new Node();
  }

  void insert(string &word) {
    Node *node = root;

    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node);
      }

      node = node->get(word[i]);
      node->increasePrefix();
    }

    node->increaseEnd();
  }

  int countWordsEqualTo(string &word) {
    Node *node = root;

    for (int i = 0; i < word.length(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
      } else {
        return 0;
      }
    }

    return node->cntEndWith;
  }

  int countWordsStartingWith(string &word) {
    Node *node = root;

    for (int i = 0; i < word.length(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
      } else {
        return 0;
      }
    }

    return node->cntPrefix;
  }

  void erase(string &word) {
    Node *node = root;

    for (int i = 0; i < word.length(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
        node->reducePrefix();
      } else {
        return;
      }
    }

    return node->deleteEnd();
  }
};

// Input:
// insert samsung
// insert samsung
// insert vivo
// erase vivo
// countWordsEqualTo samsung
// countWordsStartingWith vi

// Output:
// 2
// 0
  
// Explanation:
// insert “samsung”: we are going to insert the word “samsung” into the “TRIE”.

// insert “samsung”: we are going to insert another “samsung” word into the “TRIE”.

// insert “vivo”: we are going to insert the word “vivo” into the “TRIE”.

// erase “vivo”: we are going to delete the word “vivo” from the “TRIE”.

// countWordsEqualTo “samsung”: There are two instances of “sumsung” is present in “TRIE”.

// countWordsStartingWith “vi”: There is not a single word in the “TRIE” that starts from the prefix “vi”.
