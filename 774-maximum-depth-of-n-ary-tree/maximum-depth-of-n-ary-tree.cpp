/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int height(Node* root){
        if(root == NULL) return 0;
        int maxDepth = 0;
        for(int i=0; i<root->children.size() ; i++){
            maxDepth = max(maxDepth  , height(root->children[i]));
        }
        return maxDepth+1;
    }
    int maxDepth(Node* root) {
        if(!root) return 0 ;
        return height(root);
    }
};