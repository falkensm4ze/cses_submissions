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
    vector<pair<int,int> > v(n+1);
    v[0]=mp(0,0);
    vector<int> dp(n+1,0);
    
    for(int i=1;i<n+1;i++){
        cin>>v[i].fs>>v[i].sn;
        v[i].sn--;
        dp[i]=1;
    }
    sort(v.begin(),v.end());
    
    int p[n+1]={0};ll mx=0;
    
    for(int i=0;i<n+1;i++){
        if(i){
            if(1+dp[p[i-1]] > dp[i]){
                p[i]=p[i-1];
                dp[i]=1+dp[p[i-1]];
            }
        }
        amax(mx,dp[i]);
        
        auto j=lower_bound(v.begin()+(i+1),v.end(),mp(v[i].sn+1,v[i].sn+1));
        if(j!=v.end()){
            if(dp[(int)(j-v.begin())] <= dp[i]+1){
                dp[(int)(j-v.begin())] = 1+dp[i];
                p[(int)(j-v.begin())]=i;
            }
        }
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