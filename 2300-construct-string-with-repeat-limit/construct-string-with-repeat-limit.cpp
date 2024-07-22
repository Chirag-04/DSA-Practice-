class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        priority_queue<char>pq;
        vector<int>freq(26);
        for(auto it : s) freq[it-'a']++;
        for(int i=0 ; i<26 ; i++){
            if(freq[i] >0 ){
                pq.push((char)(i+'a'));
            }
        }
        // 
        //at max we will pick all the characters
        int n = s.size();
        string ans = "";
        while(n-- and !pq.empty()){
            char ch = pq.top();
            pq.pop();
            int ct =  min(limit , freq[ch-'a']);
            int rem = max(0 , freq[ch-'a'] - limit);
            freq[ch-'a'] = rem;
            while(ct--) ans.push_back(ch);
            if(rem == 0 or pq.empty()) continue;
            char nextCh = pq.top();
            pq.pop();
            ans.push_back(nextCh);
            freq[nextCh -'a']--;
            if(freq[nextCh -'a'] != 0) pq.push(nextCh);
            pq.push(ch);
        }
       return ans ;
    }
};