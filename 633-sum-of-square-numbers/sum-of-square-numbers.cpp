class Solution {
public:
    using ll = long long ;
    bool judgeSquareSum(int c) {
     ll lo = 0 ;
     ll hi = ceil((double)sqrt(c));
     while(lo<=hi){
        if(lo*lo + hi*hi == c) return true;
        if(lo*lo + hi*hi >c) hi--;
        else lo++;
     }   
     return false;
    }
};