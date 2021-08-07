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
    int n,L;cin>>n;
    L=(n>>1);

    vector<vector<int> > v(n);int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
    }

    vector<int> sbtr(n,1),vs(n,0);
    function <void(int)> sub = [&](int r){
        vs[r]=1;
        for(auto i: v[r]){
            if(vs[i])continue;
            sub(i);
            sbtr[r]+=sbtr[i];
        }
        return;
    };
    sub(0);

    int g=-1;

    // for(auto i: sbtr)cout<<i<<" ";
    // cout<<"\n";
      
    vs=vector<int>(n,0);
    function <void(int)> dfs = [&](int r){
        vs[r]=1;
        int nt=n-1;bool f=1;
        for(auto i: v[r]){
            if(vs[i])continue;
            dfs(i);
            if(sbtr[i]>L)f=0;
            nt-=sbtr[i];
        }
        if(nt>L)f=0;

        if(f)g=r;
        return;
    };    
    dfs(0);

    cout<<g+1<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}