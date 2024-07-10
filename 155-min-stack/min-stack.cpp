class MinStack {
public:
    stack<int>s;
    stack<int>minS;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minS.empty()) minS.push(val);
        else{
            if(val <=minS.top()) minS.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return ;
        int a = s.top();
        s.pop();
        if(!minS.empty() and minS.top() == a){
            minS.pop();
        }
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top();
    }
    
    int getMin() {
        if(minS.size() == 0) return -1;
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */