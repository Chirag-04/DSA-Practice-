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
  // method 1 is simple we will use level order traversal 
  // and if curr node is the first node then make it temp node 
  // but if curr node is not the first node then start making connection
  //method 2 we can use dfs 
    void f(Node* root){
        if(root == NULL or (!root->left and !root->right)) return ;
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        }
        f(root->left);
        f(root->right);
    }
    Node* connect(Node* root) {
         f(root);
         return root;
    }
};