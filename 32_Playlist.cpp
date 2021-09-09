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
    int n;cin>>n;
    vector<int> v(n+1);map<int,int> prev;
    for(int i=1;i<n+1;i++)cin>>v[i];
    vector<int> dp(n+1,0);
    for(int i=1;i<n+1;i++){
        dp[i]=min(1+dp[i-1],i-prev[v[i]]);
        prev[v[i]]=i;
    }

    int mx=0;
    for(auto i: dp){
        amax(mx,i);
    }

    cout<<mx<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}