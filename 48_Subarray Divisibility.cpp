#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x,mod) (((x%mod)+mod)%mod)
#define vec(T) vector<T>
#define printv(v) for(auto i: v)cout<<i<<" ";cout<<"\n";
#define scanv(v) for(auto& i: v)cin>>i;
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
    ll n;cin>>n;
    vec(ll) a(n);
    scanv(a);

    map<ll,ll> ft;ft[0]++;
    ll s=0;

    for(auto i: a){
        s+=i;
        ll r=s%n;
        r=cor(r,n);
        ft[r]++;
    }

    ll res=0;
    for(auto i: ft){
        res+=(i.sn*(i.sn-1ll));
    }

    res>>=1;

    cout<<res<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}