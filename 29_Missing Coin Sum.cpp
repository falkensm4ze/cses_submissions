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
    ll a[n];for(auto& i: a)cin>>i;
    sort(a,a+n);
    ll p=a[0];
    if(p>1){cout<<1<<"\n";return;}
    for(int i=1;i<n;i++){
        if(a[i]>p && a[i]!=p+1ll){
            cout<<p+1ll<<"\n";return;
        }
        p+=a[i];
    }
    cout<<p+1<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}