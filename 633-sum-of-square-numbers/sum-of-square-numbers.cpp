class Solution {
public:
    using ll = long long ;
    bool judgeSquareSum(int c) {
        ll l =  0;
        ll h  = ceil((double)sqrt(c));
        
        for(ll a=l ; a<=h ; a++){
            ll b = c -(a*a);
            ll lo = a;
            ll hi = h;
            while(lo<=hi){
                ll mid = lo +(hi-lo)/2;
                if(mid*mid == b){
                    return true;
                }
                else if(mid*mid > b){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
        }
        return false;
    }
};