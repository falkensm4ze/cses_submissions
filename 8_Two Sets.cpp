#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
 
typedef int64_t ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
    ll n;cin>>n;
    bool vs[n]={0};

    ll s=n*(n+1ll);
    if((s>>1ll)&1ll){cout<<"NO\n";return;}

    s>>=2ll;

    int x=0;

    for(int i=n;i>0;i--){
        x++;
        if(s<=i){vs[s-1]=1;break;}
        else {
            vs[i-1]=1;
            s-=i;
        }
    }

    cout<<"YES\n";
    cout<<x<<"\n";
    for(int i=0;i<n;i++)if(vs[i])cout<<i+1<<" ";
    cout<<"\n"<<n-x<<"\n";
    for(int i=0;i<n;i++)if(!vs[i])cout<<i+1<<" ";
    cout<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}