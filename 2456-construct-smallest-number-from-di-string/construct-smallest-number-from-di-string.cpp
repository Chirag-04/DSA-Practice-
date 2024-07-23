class Solution {
public:
    string smallestNumber(string pattern) { 
       int n =  pattern.size();
       string s(n+1 , '*');
       int gap =  0;
       char num = '1';
       for(int i=0 ; i<n ; i++){
        if(pattern[i] == 'I'){
            s[i]=num;
            num++;
            int j=i-1;
            while(gap--){
                s[j] = num;
                num = num+1;
                j--; 
            }
            gap = 0;
        } else gap++;
       }
       for(int i=s.size()-1  ; i>=0 ; i--){
       if(s[i] == '*'){
        s[i] = num;
        num = num+1;
       }

       }
        return s;
    }
};