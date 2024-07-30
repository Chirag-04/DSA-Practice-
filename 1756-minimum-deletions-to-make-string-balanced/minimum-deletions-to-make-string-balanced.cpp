class Solution {
public:
 // a a b a b b  a b 
 // i need to make something a. .. a . . b . . b
    int minimumDeletions(string s) {
        int n=s.size();
        int final=n;
        int acnt=0,bcnt=0;
        for(auto it : s){
            if(it=='b') bcnt++;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b') bcnt--;
            final=min(final
            ,acnt+bcnt);
            if(s[i]=='a') acnt++;
        }
        return final;
    }
};