   class trieNode{
    public: 
        bool isEndofWord ;
        trieNode* children[26];
        public:
        trieNode(){
            this->isEndofWord = false;
            for(int i=0 ; i<26 ; i++){
            this->children[i] = NULL;
            }
        }
    };
    trieNode* getNode(){
        trieNode* newNode =  new trieNode();
        return newNode;
    }
class Trie {
public:
    
    trieNode* root;
    Trie() {
        root =  getNode();
    }
    
    void insert(string word) {
        // let say we want to insert "apple"
        trieNode* crawler =  root;
        int i=0 ;
        for( ;i<word.size() ; i++){
            char ch =  word[i];
            int idx =  ch-'a';
            if(crawler->children[idx] == NULL){
                // no reference trie 
                   crawler->children[idx] = getNode();
            }
            crawler =   crawler->children[idx] ;
        }
        // at last at the end of word
        crawler->isEndofWord = true;
    }
    
    bool search(string word) {
        trieNode* crawler =  root;
        int i= 0;
        for( ; i<word.size() ; i++){
            char ch = word[i];
            int idx =  ch-'a';
            if(crawler->children[idx] == NULL){
                // no reference trie 
                return false;
            }
            crawler =   crawler->children[idx] ;
        }
        // at last at the end of word
       if(crawler-> isEndofWord == true) return true;
       return false;
    }
    
    bool startsWith(string word) {
         trieNode* crawler =  root;
        int i= 0;
        for( ; i<word.size() ; i++){
            char ch = word[i];
            int idx =  ch-'a';
            if(crawler->children[idx] == NULL){
                // no reference trie 
                return false;
            }
            crawler =   crawler->children[idx] ;
        }
        // at last at the end of word
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */