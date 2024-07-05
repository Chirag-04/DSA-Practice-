class Solution {
public: 
   // using the front partition concept 
    vector<vector<string>> ans;
    bool isPallindrome(int i , int j , string s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    void f(int pos , string s , vector<string>&temp){
        if(pos >= s.size()){
            ans.push_back(temp);
            return ;
        }
        //
        for(int i=pos ; i<s.size() ; i++){
            if(isPallindrome(pos , i , s)){
                // string from 
                string x= s.substr(pos , i-pos+1);
                temp.push_back(x);
                f(i+1 , s , temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        f(0 , s , temp);
        return ans ;
    }
};