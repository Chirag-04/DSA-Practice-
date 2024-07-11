class Solution {
public:
    string reverseParentheses(string s) {
        // brute force 
        int n = s.size();
        string ans;
        stack<char>st;
        for(int i=0 ; i<n ; i++){
            if(s[i] != ')'){
                st.push(s[i]);
            }
            else{
                string temp ;
                while(!st.empty() and st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                
                st.pop();
                for(auto it : temp ) st.push(it);

            }
        }
         
         while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
         }

        reverse(ans.begin() , ans.end());
        return ans;
    }
};