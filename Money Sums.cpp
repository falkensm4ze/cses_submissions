#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back

typedef int64_t ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
	int n;cin>>n;int x[n];
    for(auto& i: x)cin>>i;
    set<int> v;int sz=1e5+1;
    bool dp[n+1][sz];memset(dp,0,sizeof(bool)*(n+1)*sz);
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sz;j++){
            if(dp[i-1][j])dp[i][j]=1;
            else if(j>=x[i-1] && dp[i-1][j-x[i-1]])dp[i][j]=1;
            if(dp[i][j])v.insert(j);
        }
    }
    v.erase(0);
    cout<<v.size()<<"\n";
    for(auto i: v)cout<<i<<" ";
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