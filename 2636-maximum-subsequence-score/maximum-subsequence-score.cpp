class Solution {
public:
    using ll = long long ;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n = nums1.size();
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({nums2[i] , nums1[i]});
        }
        // ok done 
        sort(v.begin(),v.end() , greater<pair<int,int>>());

        ll ans  = 0 ;
        ll sum = 0 ;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0 ;i<=k-1 ; i++){
            sum+=v[i].second;
            pq.push(v[i].second);
        }
        ans =  sum*1LL*v[k-1].first;
        for(int  i=k ; i< n ;i++){ 
                sum+=v[i].second-pq.top();   
                pq.pop();
                ans = max(ans , sum*1LL*v[i].first);
                pq.push(v[i].second);
        }
        return ans ;
    }
};