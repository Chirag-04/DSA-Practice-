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
   // we can make use of level orfer traversal
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* temp =  q.front();
            int sz = q.size();
            bool firstNode = true;
            for(int i=0; i <sz ; i++){
                Node* newNode = q.front();
                q.pop();
                if(firstNode){
                    firstNode= false;
                }
                else{
                    temp->next =  newNode;
                    temp = newNode;
                }
                if(newNode->left) q.push(newNode->left);
                if(newNode->right) q.push(newNode->right);

            }
            temp->next == NULL;
        }
        return root;
    }
};