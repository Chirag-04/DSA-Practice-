class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // i will pick the first string 
        string ans= "";
        for(int i=0; i <strs[0].size() ; i++){
            char ch =  strs[0][i];
            for(int j=1 ; j<strs.size() ; j++){
                if(ch != strs[j][i]) return ans;
            }
            ans+=ch;
        }
        return ans;
    }
};