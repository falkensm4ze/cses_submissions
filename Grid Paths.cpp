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
    string s[n];
    for(auto& i: s){cin>>i;assert(i.size()==n);}
    vector<vector<int> > dp(n,vector<int>(n,0));
    if(s[0][0]!='*')dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='*')continue;
            if(i>0)dp[i][j]+=dp[i-1][j];
            if(j>0)dp[i][j]+=dp[i][j-1];
            dp[i][j]=cor(dp[i][j]);
        }
    }

    cout<<cor(dp[n-1][n-1])<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}