class Solution {
public:
    using pii = pair<int, pair<int, char>>;
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        stack<pii> s;
        vector<pii>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({pos[i] , {h[i] , dir[i]}});
        }
        sort(v.begin() , v.end());
        for (int i = 0; i < n; i++) {
                        // collision
            int b_hel = v[i].second.first;
            int b_pos = v[i].first;
            char b_dir = v[i].second.second;
            
            if (s.empty() || b_dir == 'R' || (!s.empty() && s.top().second.second == b_dir)) {
                s.push({b_pos, {b_hel, b_dir}});
                continue;
            }
            while (!s.empty() && s.top().second.second == 'R') {
                int a_hel = s.top().second.first;
                int a_pos = s.top().first;
                if(a_hel == b_hel){
                    s.pop();
                    b_hel = 0;
                    break;
                }else if(a_hel > b_hel){
                    s.top().second.first -=1;
                    b_hel = 0;
                    break;
                }
                else {
                    s.pop();
                    b_hel-=1;
                }
            }
            
            if (b_hel > 0) {
                s.push({b_pos, {b_hel, b_dir}});
            }
        }
        
        unordered_map<int, int> m;
        while (!s.empty()) {
            m[s.top().first] = s.top().second.first;
            s.pop();
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (m.count(pos[i])) {
                ans.push_back(m[pos[i]]);
            }
        }
        return ans;
    }
};
