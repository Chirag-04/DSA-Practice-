#include<bits/stdc++.h>
   using namespace std ;
   #define ll               long long 
   #define F                first
   #define S                second 
   #define pb               push_back
   #define vi               vector<int>
   #define pii              pair<int,int>
   #define all(p)           p.begin(),p.end()
//_________________________________________
const int M = 1e9+7;
  ll mod (ll x){
      return (x%M + M)%M;
   }
  ll mul(ll a , ll b){
       return mod((mod(a) * mod(b)));
   }

 void solve() {
    int n , m , k;
    cin >> n >> m  >> k;
    int money = 0;
    if(k < m*2){
        int offer =  n/2;
        money+=(offer)*k;
        if(n%2!=0) money+=m;
    }
    else{
        money+=(n*m);
    }
    cout<<money<<endl;
  }

 int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     ll t;
     cin >> t;
      while(t--){
           solve();
        }

    return 0;
 }