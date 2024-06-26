class Solution {
  public:
  int countNode(struct Node* root) {
    if(root == NULL) {
      return 0;
    }
    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
  }
  
  bool isCBT(struct Node* root, int index, int cnt) {
    if(root == NULL) {
      return true;
    }
    if(index >= cnt) {
      return false;
    } 
    else {
      bool left = isCBT(root->left, 2*index+1, cnt);
      bool right = isCBT(root->right, 2*index+2, cnt);
      return (left && right);
    }
  }
  
  bool ismaxOrder(struct Node* root) {
    if(root->left == NULL && root->right == NULL){
      return true;
    }
    
    if(root->right == NULL) {
      return (root->left->data < root->data);
    }  
    else {
      bool left = ismaxOrder(root->left);
      bool right = ismaxOrder(root->right);
          
      return left && right &&
        (root->left->data < root->data && root->right->data < root->data);
    }
  }
  
  bool isHeap(struct Node* root) {
    int index = 0;
    int totalNode = countNode(root);
        
    if(isCBT(root, index, totalNode) && ismaxOrder(root)) {
      return true;
    }
    return false;
  }
};

// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 0
