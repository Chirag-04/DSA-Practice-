  class MyHashSet {
public:
    // brute force 
    // as in the problem it is given that we can create the set of size of n 
    vector<bool>check;
    MyHashSet() {
        check.resize(1e6+2 ,  false);
    }
    
    void add(int key) {
        check[key]= true;
    }
    
    void remove(int key) {
        check[key]= false;
    }
    
    bool contains(int key) {
        return check[key] == true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */