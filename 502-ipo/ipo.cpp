class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<pair<int,int>>store;
        int n = capital.size();
        // so i need to explore all project withing given budget
        for(int i=0 ; i<n ; i++){
            store.push_back({capital[i] , profits[i] });
        }
        sort(store.begin() , store.end());
        int ans  =  w;
        int i=0 ;
        priority_queue<int> pq;
        while(k--){
            // selecting an item
            while(i<n and ans>=store[i].first){
                // withing budget
                // cout<<ans<<" "<<store[i].first<<endl;
                pq.push(store[i].second);
                i++;           
            }
            // cout<<i<<pq.top()<<endl;

            //we need to make that an element should be present 
            if(pq.empty()) break;
            ans+=pq.top();
            pq.pop();
        }
        // cout<<ans<<endl;
        return ans;
    }
};