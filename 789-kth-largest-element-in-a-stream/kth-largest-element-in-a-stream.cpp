class KthLargest {
public:
// since we need the kth largest element everytie 
// so we can either go gor min or max queue
// but we will take max queue
// cuz we wkill take max queue then i will lose all the k-1 large element
// and it possible the i need them in future 
// so i need to preserve the max elements
    int K;
    priority_queue<int,vector<int> , greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto it : nums){
            pq.push(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()!=K ) pq.pop();
        return pq.top();  
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */