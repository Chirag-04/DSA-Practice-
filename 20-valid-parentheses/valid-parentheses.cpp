class Solution {
public:
    bool isValid(string t) {
        int n =  t.size();
        stack<int>s;
        for(int i = 0 ; i<n ; i++){
            if(t[i] == '(' or t[i] == '{' or t[i] == '['){
                s.push(t[i]);
                continue;
            }
            // closing bracket;
            if(s.empty()) return false;
            if(t[i]== ')' and s.top() != '(') return false;
            else if(t[i] == '}' and s.top() != '{') return false;
            else if(t[i]== ']' and s.top()!='[') return false;
            else s.pop();
        }
        return s.empty() ? 1:0;
    }
};