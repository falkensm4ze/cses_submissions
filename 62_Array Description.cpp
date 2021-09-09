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
	int n,m;cin>>n>>m;
    int x[n];
    int sz = m+2;
    for(auto& i: x)cin>>i;
    vector<vector<int>> dp(n,vector<int>(sz,0));
    
    if(x[0])dp[0][x[0]]=1;
    else {
        for(int i=1;i<m+1;i++)dp[0][i]=1;
    }

    for(int i=1;i<n;i++){
        if(x[i]){ 
            dp[i][x[i]] += dp[i-1][x[i]-1];
            dp[i][x[i]] = cor(dp[i][x[i]]);
            dp[i][x[i]] += dp[i-1][x[i]];
            dp[i][x[i]] = cor(dp[i][x[i]]);
            dp[i][x[i]] += dp[i-1][x[i]+1];
            dp[i][x[i]] = cor(dp[i][x[i]]);
        }
        else {
            for(int j=1;j<m+1;j++){
                dp[i][j] += dp[i-1][j-1];dp[i][j] = cor(dp[i][j]);
                dp[i][j] += dp[i-1][j+1];dp[i][j] = cor(dp[i][j]);
                dp[i][j] += dp[i-1][j];dp[i][j] = cor(dp[i][j]);
            }
        }
    }

    int r=0;
    for(int i=1;i<m+1;i++){r+=cor(dp[n-1][i]);r=cor(r);}
    cout<<cor(r)<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}