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
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
    int n,x;cin>>n>>x;
    map<ll,vector<int>> m1;
    vec(ll) a(n,0);scanv(a);
    vec(ll) s(n+1,0);ll c=0;
    m1[0].pb(0);
    for(int i=1;i<n+1;i++){
        s[i]=s[i-1]+a[i-1];
        m1[s[i]].pb(i);
    }

    for(int i=1;i<n+1;i++){
        auto j=lower_bound(m1[s[i]-x].begin(),m1[s[i]-x].end(),i);
        c+=(ll)(j-m1[s[i]-x].begin());
    }

    cout<<c<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}