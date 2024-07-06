class Solution {
public:
    int passThePillow(int n, int time) {

        int i =  1;
        bool ltor = false , rtol = false;
        while(time--){
            if(i==1){
                ltor = true;
                rtol= false;
            }
            if(i==n){
                ltor = false;
                rtol = true;
            }
            if(ltor) i++;
            else if(rtol) i--;
        }
        return i;
    }
};