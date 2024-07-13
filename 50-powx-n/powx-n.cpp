class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n < 0){
            x= 1/x;
            n = abs(n);
        }
        double sub = myPow(x , n/2);
        if(n%2 ==0 ) return sub*sub;
        else return x*sub*sub;
    }
};