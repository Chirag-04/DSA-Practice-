class TrieNode{
    public:
    bool isEnd;
    TrieNode* children[26];
    int childCount;
    TrieNode(){
        this->isEnd  = false;
        this->childCount  = 0;
        for(int i=0; i<26 ; i++){
            this->children[i] = NULL;
        }
    }
};
TrieNode* getNode(){
    TrieNode* new_node = new TrieNode();
    return new_node;
}
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = getNode();
    }

    void insert(string word){
        TrieNode* crawler = root;
        int i=0 ;
        for(; i <word.size() ; i++){
            int idx =  word[i] - 'a';
            if(crawler->children[idx] == NULL){
               crawler->children[idx] =  getNode();  
               crawler->childCount++;  
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    void lcp(string first , string&ans){
         TrieNode* crawler = root;
        for(int i=0 ; i<first.size() ; i++){
            int idx = first[i] -'a';
            if(crawler->children[idx] && crawler->childCount == 1 && !crawler->isEnd){
                ans.push_back(first[i]);
            }else break;
            crawler = crawler->children[idx];
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        for(int i=0 ; i<strs.size();  i++){
            t->insert(strs[i]);
        }
        string first = "";
        string ans = "";
        t->lcp(strs[0] , ans);
        return ans;
    }
};