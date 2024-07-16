class MyQueue {
public:
    stack<int>s;
    stack<int>t;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(t.size() !=0){
            int x = t.top();
            t.pop();
            return x;
        }   
        // else 
        while(s.size()){
            int a = s.top();
            s.pop();
            t.push(a);
        }
        int x = t.top();
        t.pop();
        return x;
    }
    
    int peek() {
            if(t.size() !=0){
            int x = t.top();
            return x;
        }   
        // else 
        while(s.size()){
            int  a = s.top();
            s.pop();
            t.push(a);
        }
        int x = t.top();
        return x;
    }
    
    bool empty() {
        return (s.size()==0 and t.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */