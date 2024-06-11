class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
     // we can again make use of the counting sort algo
     // first storing the freq then decreaing the freq
     vector<int>freq(1001, 0);
     for(int i=0;  i<arr1.size() ; i++) freq[arr1[i]]++;
     int j=0 ;
     vector<int>ans;
     while(j < arr2.size()){
        int num  = arr2[j];
        while(freq[num]){
            ans.push_back(num);
            freq[num]--;
        }
        j++;
     }
     // there could be mutiple occurence of left over element as well

     for(int i=0 ; i<1001 ; i++){
       while(freq[i]){
        ans.push_back(i);
        freq[i]--;
       }
     }
     return ans ;
    }
};