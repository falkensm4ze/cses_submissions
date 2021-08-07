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
    vector<vector<int> > v(n);int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
    }

    vector<ll> d(n,0),ans(n,0);            
    function <void(int)> bfs = [&](int r){                
        queue<int> q;
        q.push(r);
        d[r]=1ll;                
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i: v[x]){
                if(d[i]==0){
                    d[i] = d[x]+1ll;
                    q.push(i);
                }
            }
        }                
        for(auto &i: d){
            i--;
        }
    };
    bfs(0);
    for(auto i: d){
        ans[0]+=i;
    }

    vector<bool> vs(n,0);vector<ll> sb(n,1);      
    function <int(int)> dfs1 = [&](int r){
        vs[r]=1;
        for(auto i: v[r]){
            if(!vs[i]){
                sb[r]+=dfs1(i);
            }
        }
        return sb[r];
    };
    dfs1(0);
    vs=vector<bool>(n,0);

    function <void(int)> dfs2 = [&](int r){
        vs[r]=1;
        for(auto i: v[r]){
            if(!vs[i]){
                ans[i]=ans[r]+n-2ll*sb[i];
                dfs2(i);
            }
        }
        return;
    };

    dfs2(0);

    for(auto i: ans)cout<<i<<" ";
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