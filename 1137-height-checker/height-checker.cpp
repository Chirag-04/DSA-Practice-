class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // since the memory given to us is small 
        // so we can make use of the coutning sort algo
        int n =  heights.size();
        vector<int>freq(101,0);
        for(int i=0;  i<n ; i++) freq[heights[i]]++;
        // stored the freq
        int j=0 ; 
        while(freq[j]==0) j++;
        int ans= 0 ;
        int i= 0 ;
        while(i<n){
            if(freq[j] == 0){
                j++;
            }
            else{
            if(heights[i] != j) ans++;
            freq[j]--;
            if(freq[j] == 0)j++;
            i++;
            }    
        }
        return ans; 
    }
};