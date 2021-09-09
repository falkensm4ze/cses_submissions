#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
#define vec(T) vector<T>
#define printv(v) for(auto i: v)cout<<i<<" ";cout<<"\n";
#define scanv(v) for(auto& i: v)cin>>i;
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
const ll inf = 1e15;
 
//void precomp(){}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n);int x,y,wt;
    map<pair<int,int>,ll> edg;
    for(int i=0;i<m;i++){
        cin>>x>>y>>wt;
        edg[mp(x-1,y-1)]=(-wt);
        v[x-1].pb(y-1);
    }

    vector<ll> d(n,inf);
    function <ll(int,int)> bellford = [&](int src,int dest){
        d[src]=0;ll res;
        for(int i=0;i<n;i++){
            for(auto i: edg){
                amin(d[i.fs.sn],i.sn+d[i.fs.fs]);
            }
        }
        res=d[dest];
        for(int i=0;i<n;i++){
            for(auto i: edg){
                if(d[i.fs.sn]>i.sn+d[i.fs.fs]){
                    return 1ll;
                }
            }
        }

        return res;
    };

    cout<<(-bellford(0,n-1))<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    //precomp();
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}