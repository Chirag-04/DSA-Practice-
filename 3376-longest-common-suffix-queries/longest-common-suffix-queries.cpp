class TrieNode{
    public :
    bool isEnd;
    TrieNode* children[26];
    int index;
    int sz;
    TrieNode(){
        this->isEnd=  false;
        for(int i=0; i<26 ; i++){
            this->children[i] = NULL; 
        }
        this->index = -1;
        this->sz = INT_MAX;
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

    void insert(string word , int st){
        TrieNode*crawler =root;
        int wsize = word.size();
        int i=0 ;
        for(; i<word.size() ; i++){
            int idx =  word[i]-'a';
            if(crawler->children[idx] == NULL){
                crawler->children[idx] = getNode();
            }
            if(crawler->children[idx]->sz >  wsize){
                crawler->children[idx]->sz = wsize;
                crawler->children[idx]->index = st;
            }
            crawler = crawler->children[idx];
        }
        crawler->isEnd = true;
    }

    int search(string word){
        TrieNode*crawler =root;
        int i=0 ;
        for(; i<word.size() ; i++){
            int idx =  word[i]-'a';
            if(crawler->children[idx] == NULL ){
                break  ;           
            }
            crawler = crawler->children[idx];
        }
       return crawler->index;
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>& query) {
        Trie* t = new Trie();
        for(int i=0 ; i<words.size() ; i++){
            reverse(words[i].begin() , words[i].end());
            t->insert(words[i] , i);
        }
        //
        vector<int>ans;
        for(auto it: query){
            reverse(it.begin() , it.end());
            int index =  t->search(it);
            ans.push_back(index);
        }

        int uind = -1;
        int usz =  INT_MAX;
        for(int i=0; i<words.size() ; i++){
            if(usz > words[i].size()){
                usz =  words[i].size();
                uind =  i;
            }
        }

        for(int i=0 ; i<ans.size() ; i++){
            if(ans[i] == -1) ans[i] = uind;
        }
        
        return ans ;
    }
};