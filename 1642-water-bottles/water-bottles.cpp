class Solution {
public:
    int numWaterBottles(int numBottles, int ex) {
        int ans  =  numBottles;
        int rem = 0 ;
        while(numBottles >= ex ){
            ans+=(numBottles)/ex;
            numBottles = (numBottles/ex)+(numBottles%ex);
        }
        return ans;
    }
};