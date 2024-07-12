class Solution {
public:
    int ct1=0;
    stack<char>st;
    void help(string s , char c1 , char c2){
        // c1 c2
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == c2){
                if(!st.empty() and st.top()== c1 ){
                    ct1++;
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
    }
    int maximumGain(string s, int x, int y) {
        // y > x  --> ba
        char c1 , c2;
        if(y > x) {
            c1 = 'b';
            c2 = 'a';
        }
        else {
            c1 = 'a' ;
            c2 =  'b';
        }
        help(s , c1 , c2);
        int p =ct1;
        ct1= 0;
       string t;
       while(!st.empty()){
        t+=st.top();
        st.pop();
       }
        help(t , c1 , c2);
      int q = ct1;
      
      int ans  = 0;
      cout<<p<<" "<<q<<endl;
      if(y > x){
        ans+=(p*y);
        ans+=(q*x);
      }
      else {
        ans+=(p*x);
        ans+=(q*y);
      }
     
    return ans;
    }
};