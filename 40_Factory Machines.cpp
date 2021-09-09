#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
#define vec(T) vector<T>
#define printv(v) for(auto i: v)cout<<i<<" ";cout<<"\n";
#define scanv(v) for(auto& i: v)cin>>i;
#define sortv(x) sort(x.begin(),x.end())
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
    ll n,t;cin>>n>>t;
    vec(ll) a(n);
    scanv(a);
    sortv(a);

    ll l=1,r=t*a[0];

    while(l<r){
        ll x=0,m=l+r;m>>=1ll;
        for(ll i=0;i<n;i++){
            x+=m/a[i];
        }

        if(x>=t){
            r=m;
        }
        else {
            l=m+1ll;
        }
    }

    ll m=l+r;m>>=1ll;

    cout<<m<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}