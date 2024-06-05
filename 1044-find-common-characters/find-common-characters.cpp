class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans ;
        vector<int>common(26 , INT_MAX);
        int n = words.size();
        for(auto s : words){
            vector<int>temp(26 ,0);
            for(auto it :s ){
                temp[it - 'a']++;
            }
            // if temp[it] == 0 that means that particular didnt appear
            // and hence it cant be the part of the answer 
            // and we also also we need the min count of the charactes
            // so all those characters who have their temp[i] = 0
            // will also have final[i] = 0;
            for(int j=0 ; j<26 ; j++){
                common[j] =  min(common[j] , temp[j]);
            }
        }

        // now the final[i] == 0 depicts that in atleast one string that particular character didnt appear 
        for(int i=0 ; i< 26 ; i++){
            for(int j=0 ; j<common[i] ; j++){
                ans.push_back(string(1 , i+'a'));
            }
        }
        return ans;
    }


};