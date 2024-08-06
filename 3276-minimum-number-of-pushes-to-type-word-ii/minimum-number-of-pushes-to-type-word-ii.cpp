class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char , int > m; // constant space 
        for(int i=0; i < word.size() ; i++){
            m[word[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto it : m){
            v.push_back({it.second , it.first});
        }
        sort(v.begin() , v.end() , greater());
        int ans  = 0 ;
        int i=0;
        int ct = 0 ;
        int type = 1;
        while(i <v.size()){
            if(ct == 8){
                type++;
                ct = 0;
            }
            ans+=(v[i].first*type);
            ct++; 
            i++;       
        }
    return ans ;
    }
};