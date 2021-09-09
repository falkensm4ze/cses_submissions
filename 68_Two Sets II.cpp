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

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}
 
int mul(int x, int y){
    return (x * 1ll * y) % mod;
}
 
int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
int inv(int x){
    return binpow(x, mod - 2);
}
 
int divide(int x, int y){
    return mul(x, inv(y));
}

//void precomp(){}
 
void solve(){
    int n;cin>>n;int x[n];
    iota(x,x+n,1);
    
    int sz=n*n+1;
    
    int dp[n+1][sz];memset(dp,0,sizeof(int)*(n+1)*sz);
    
    int s = (n*(n+1))>>1;
    if(s&1){cout<<"0\n";return;}
    else s>>=1;
 
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sz;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=x[i-1])dp[i][j]+=dp[i-1][j-x[i-1]];
            dp[i][j]=cor(dp[i][j]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }

    dp[n][s]=divide(dp[n][s],2);
 
    cout<<cor(dp[n][s])<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}