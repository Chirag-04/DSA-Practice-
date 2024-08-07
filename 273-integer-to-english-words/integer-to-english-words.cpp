class Solution {
public:
    // interger range 
    // 10^8 
    // million 1000000
    // 1billion = 100000000 = 10^8

void fill_map(std::unordered_map<int, std::string>& m) {
    m[0] = "Zero";
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";
    m[4] = "Four";
    m[5] = "Five";
    m[6] = "Six";
    m[7] = "Seven";
    m[8] = "Eight";
    m[9] = "Nine";
    m[10] = "Ten";
    m[11] = "Eleven";
    m[12] = "Twelve";
    m[13] = "Thirteen";
    m[14] = "Fourteen";
    m[15] = "Fifteen";
    m[16] = "Sixteen";
    m[17] = "Seventeen";
    m[18] = "Eighteen";
    m[19] = "Nineteen";
    m[20] = "Twenty";
    m[30] = "Thirty";
    m[40] = "Forty";
    m[50] = "Fifty";
    m[60] = "Sixty";
    m[70] = "Seventy";
    m[80] = "Eighty";
    m[90] = "Ninety";
    m[100] = "One Hundred";
    m[200] = "Two Hundred";
    m[300] = "Three Hundred";
    m[400] = "Four Hundred";
    m[500] = "Five Hundred";
    m[600] = "Six Hundred";
    m[700] = "Seven Hundred";
    m[800] = "Eight Hundred";
    m[900] = "Nine Hundred";
    m[1000] = "Thousand";
    m[1000000] = "Million";
    m[1000000000] = "Billion";
}
    string numberToWords(int num) {
        string s =  to_string(num);
        vector<string>v;
        int n = s.size();
        int i = n-1;
        while(i>=0){
            string temp="";
            int x = 3;
            while(x-- and i>=0){
                temp.push_back(s[i]);
                i--;
            }
            reverse(temp.begin() , temp.end());
            v.push_back(temp);
        }

        unordered_map<int,string>m;
        fill_map(m);
        reverse(v.begin() , v.end());
         for(auto it : v){
            cout<<it<<" ";
        }
        cout<<endl;
        string ans ="";
        int vsz= v.size();
        for(int i=0 ; i<v.size() ; i++){
            int nums= stoi(v[i]);
            string call= "";
            if(v[i].size() == 1) call = m[nums]+" ";
            else if(v[i].size() == 2){
                if(m.count(nums)) call = m[nums]+" ";
                else{
                    string a  = m[(v[i][0]-'0')*10];
                    string b =   m[v[i][1]-'0'];
                    if(a!="Zero" and b!="Zero") call +=  a+" ";
                    if(b!="Zero") call+=(b+" ");
                }
            }
            else if(v[i].size()==3){
                string a = m[(v[i][0]-'0')*100];
                string b =m[(v[i][1]-'0')*10];
                string c =m[v[i][2]-'0'];
               if(a!="Zero")call += a+" ";
               if((v[i][1]-'0') == 1){
                call+= m[(v[i][1]-'0')*10+ (v[i][2]-'0') ]+ " " ;
               }else{

               
               if(b!="Zero")call += b+" ";
               if(c!="Zero") call += c+" ";
               }

            }
            ans+=call;
            if(nums!=0 and vsz-i == 4) ans+="Billion ";
            else if(nums!=0 and vsz-i == 3) ans+="Million ";
            else if(nums!=0 and vsz-i == 2) ans+="Thousand ";
        }
        if(ans.back() == ' ') ans.pop_back();
      return ans;
    }
};