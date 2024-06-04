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
    ll n , k;
    cin >> n >> k;
    vector<ll>v(n);
    ll sum = 0 ;
    for(int i=0 ; i<n ; i++){
        cin>>v[i];
        sum+=v[i];
    }
    
    ll front =  (k+1)/2;
    ll back = (k/2);
    
    ll fsum = 0  , bsum = 0;
    ll i =0 ;
    for(; i<n ; i++){
        if(front >=v[i])
        front-=v[i];
       else break;
    }

    ll j=n-1;
    for( ; j>=0 ; j--){
       if(back >=v[j]) back-=v[j];
        else  break;
    }
    // cout<<front<<" "<<back<<" "<<i<<" "<<j<<" ";
    ll ans = 0 ;
    if(i>j){
       ans +=n;
    }else{
     ans+=n-(j-i+1);
    }

    if(i==j){
        if(front+back >= v[i]) ans++;
    }
    cout<<ans<<endl;


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