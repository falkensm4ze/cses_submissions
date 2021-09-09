#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 
//void precomp(){}

void solve(){
    int n;cin>>n;
    ll a[n];
    for(auto& i: a)cin>>i;
    sort(a,a+n);ll x=0;
    if(n&1)x=a[((n+1)>>1)-1];
    else x=a[(n>>1)-1];
    ll r=0;
    for(int i=0;i<n;i++){
        r+=abs(a[i]-x);
    }

    cout<<r<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}