/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void f(TreeNode* root , string&s){
        if(root == NULL){
            s.push_back('#');
            return ;
        }
        s.append(to_string(root->val) + ",");
        f(root->left , s);
        f(root->right , s);

    }
    string serialize(TreeNode* root) {
        string s;
        f(root , s);
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* decode(string&data){
        if(data.size() == 0) return NULL;
        if(data[0] == '#'){
            // null node 
            data = data.substr(1);
            return NULL;
        }
        //
        int index = 0;
        string s= "";
        while(data[index]!=','){
            s.push_back(data[index]);
            index++;
        }
        TreeNode* root = new TreeNode(stoi(s));
        data = data.substr(index+1);
        root->left=  decode(data);
        root->right = decode(data);
        return root;
    }
    TreeNode* deserialize(string data) {
        if(data.size()<=1 ) return NULL;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;