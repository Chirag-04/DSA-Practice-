class MyStack {
public:
    deque<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = q.size();
        q.push_back(x);
        while(sz--){
            int a =  q.front();
            q.pop_front();
            q.push_back(a);
        }
    }
    
    int pop() {
       int a =  q.front();
       q.pop_front();
       return a;
    }
    
    int top() {
        return q.front();  
    }
    
    bool empty() {
        return (q.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */