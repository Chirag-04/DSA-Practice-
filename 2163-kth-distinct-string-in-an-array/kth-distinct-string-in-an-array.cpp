class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> m;
        for(int i=0 ; i<arr.size() ; i++){
            string it =  arr[i];
            if(m.count(it)){
                m[it] = -1;
            }
           else m[it]=  i;
        }
        vector<pair<int,string>>v;
        for(auto it : m){
            if(it.second!=-1) v.push_back({it.second , it.first});
        }
        sort(v.begin() , v.end());
        if(v.size() < k ) return "";
        return v[k-1].second;
    }
};