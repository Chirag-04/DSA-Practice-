class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<pair<int,int>>freq(26);
        char ch ='a';
        for(int i=0 ; i< 5 ; i++){
            for(int j=0 ; j<5 ; j++){
                freq[ch-'a'] ={i , j};
                ch++;
            }
        }
        freq['z'-'a'] = {5,0};
        // for(int i=0 ; i<freq.size() ; i++){
        //     cout<<freq[i].first<<" "<<freq[i].second<<endl;
        // }
        string t="";
        char prevCh = 'a';
        for(int i=0 ; i<target.size() ; i++){
            char newCh = target[i];
            int delr =  freq[prevCh-'a'].first - freq[newCh-'a'].first;
            int delc = freq[ prevCh- 'a'].second - freq[newCh-'a'].second;

            if(prevCh =='z'){
                for(int i=0 ; i<abs(delr) ; i++){
                if(delr<0) t+='D';
                else t+='U';
               
            }
            for(int i=0 ; i<abs(delc) ; i++){
              if(delc<0)  t+='R';
              else t+='L';
            }
            }
            else{
                
            
            for(int i=0 ; i<abs(delc) ; i++){
              if(delc<0)  t+='R';
              else t+='L';
            }


            for(int i=0 ; i<abs(delr) ; i++){
                if(delr<0) t+='D';
                else t+='U';
               
            }
    }
            t+='!';
            prevCh = newCh;

        }
       return t;
    }
};