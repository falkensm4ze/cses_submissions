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
        int n;cin>>n;ll a[n];
        for(auto& i: a)cin>>i;
        
        ll s[n]={0};
        vector<vector<pair<ll,ll> > > dp(n,vector<pair<ll,ll> >(n,mp(0,0)));
        
        s[0]=a[0];dp[0][0]=mp(a[0],0);
        for(int i=1;i<n;i++){
            dp[0][i]=mp(a[i],0);
            s[i]=s[i-1]+a[i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j+i<n;j++){
                dp[i][j].fs=max(dp[i-1][j].sn+a[j+i],dp[i-1][j+1].sn+a[j]);
                if(j>0)dp[i][j].sn=s[j+i]-s[j-1]-dp[i][j].fs;
                else dp[i][j].sn=s[j+i]-dp[i][j].fs;
            }
        }

        cout<<dp[n-1][0].fs<<"\n";    
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}