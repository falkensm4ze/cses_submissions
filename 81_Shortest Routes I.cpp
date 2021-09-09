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
const ll inf = 1ll<<62;
 
//void precomp(){}

vector<ll> djkst(vector<vector<pair<int,ll> > > &g){
    int n=g.size();
    set<pair<ll,int> > s;vector<bool> vs(n,0);
    vector<ll> d(n,inf);d[0]=0;
    for(int i=0;i<n;i++){
        s.insert(mp(d[i],i));
    }
    while(s.size()){
        auto i = s.begin();
        if(i->fs==inf)break;
        for(auto j: g[i->sn]){
            if(vs[j.fs])continue;
            if(d[j.fs]>i->fs+j.sn){
                s.erase(mp(d[j.fs],j.fs));
                s.insert(mp(i->fs+j.sn,j.fs));
                d[j.fs]=i->fs+j.sn;
            }
        }
        vs[i->sn]=1;
        s.erase(*i);
    }
    return d;
}
 
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,ll> > > v(n);int x,y,dis;
    for(int i=0;i<m;i++){
        cin>>x>>y>>dis;
        v[x-1].emplace_back(mp(y-1,dis));
        //v[y-1].emplace_back(mp(x-1,dis));
    }

    vector<ll> d=djkst(v);
    for(auto i: d){
        cout<<i<<" ";
    }
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