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
	int n,x;cin>>n>>x;
    int h[n],s[n];
    int sz = x+1;
    for(auto& i: h)cin>>i;
    for(auto& i: s)cin>>i;
    int dp[n][sz];memset(dp,0,sizeof(int)*sz*n);
    
    for(int i=0;i<sz;i++){
        if(i>=h[0])dp[0][i]=s[0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<sz;j++){
            if(j<h[i])dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-h[i]]+s[i]);
        }
    }

    cout<<dp[n-1][x]<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}