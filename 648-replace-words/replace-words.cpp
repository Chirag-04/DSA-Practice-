class TrieNode{
    public :
    bool isEnd;
    TrieNode* children[26];
    
    TrieNode(){
        this->isEnd=  false;
        for(int i=0; i<26 ; i++){
            this->children[i] = NULL; 
        }
    }
};
 TrieNode* getNode(){
    TrieNode* node =  new TrieNode();
    return node;
 }
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root= getNode();
    }

    void insert(string word){
        TrieNode*crawler =root;
        int i=0 ;
        for(; i<word.size() ; i++){
            int idx =  word[i]-'a';
            if(crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    string search(string word){
        TrieNode*crawler =root;
        int i=0 ;
        for(; i<word.size() ; i++){
            int idx =  word[i]-'a';
            if(crawler->children[idx] == NULL ){
                break  ;           
            }
            crawler = crawler->children[idx];
            if(crawler->isEnd == true){
                return word.substr(0 , i+1);
            }
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dic, string sen) {
        Trie* t =  new Trie();
        for(auto it:dic){
            t->insert(it);
        }
        // lets tokenize 
        stringstream ss(sen);
        string token = "";
        vector<string>temp;
        while(getline(ss , token , ' ')){
            temp.push_back(token);
        }

        string ans="";
        for(int i=0 ; i<temp.size() ; i++){
            string repl = t->search(temp[i]);
            ans+=repl;
           if(i<temp.size()-1) ans.push_back(' ');
        }
        return ans ;
    }
};