/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      do_bfs(root, nullptr);
      return root;
    }
  
    void do_bfs(Node *parent, Node *right) {
      if (parent == nullptr) { return; }
      
      parent->next = right;
      do_bfs(parent->right, (right == nullptr ? nullptr : right->left));
      do_bfs(parent->left, parent->right);
    }
};


// can use current structure and get right from there (not passing it as a param)
