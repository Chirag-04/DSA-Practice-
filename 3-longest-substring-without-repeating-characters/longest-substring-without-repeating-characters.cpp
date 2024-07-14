class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i=0  , j=0  , len = 0  , n = s.size();
        while(j < n){
            m[s[j]]++;
            if(j-i+1 == m.size()){
                len = max(len , j-i+1);
                j++;
            }
            else {
                while(i<=j and j-i+1!=m.size()){
                    m[s[i]]--;
                    if(m[s[i]] == 0) m.erase(s[i]);
                    i++;
                }
                len = max(len , j-i+1);
                j++;
            }
        }
       return len;
    }
};