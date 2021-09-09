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

ll dikst(vector<vector<pair<int,ll> > > &g){
    int n=g.size();
    set<pair<ll,int> > s;vector<bool> vs(n,0);
    vector<ll> d1(n,inf),d2;d1[0]=0; // Assumed 0 as start
    //vector<int> pr(n);iota(pr.begin(),pr.end(),0);  //parent array to obtain path
    for(int i=0;i<n;i++){
        s.insert(mp(d1[i],i));
    }
    while(s.size()){
        auto i = s.begin();
        if(i->fs==inf)break;
        for(auto j: g[i->sn]){
            if(vs[j.fs])continue;
            if(d1[j.fs]>i->fs+j.sn){
                s.erase(mp(d1[j.fs],j.fs));
                s.insert(mp(i->fs+j.sn,j.fs));
                d1[j.fs]=i->fs+j.sn;
                //pr[j.fs]=i->sn;      //for path formation
            }
        }
        vs[i->sn]=1;
        s.erase(*i);
    }
    vs=vector<bool>(n,0);d2=d1;
    for(int i=0;i<n;i++){
        s.insert(mp(d2[i],i));
    }
    while(s.size()){
        auto i = s.begin();
        if(i->fs==inf)break;
        for(auto j: g[i->sn]){
            if(vs[j.fs])continue;
            if(d2[j.fs]>min(i->fs+j.sn,d1[i->sn]+j.sn/2)){
                s.erase(mp(d2[j.fs],j.fs));
                s.insert(mp(min(i->fs+j.sn,d1[i->sn]+j.sn/2),j.fs));
                d2[j.fs]=min(i->fs+j.sn,d1[i->sn]+j.sn/2);
                //pr[j.fs]=i->sn;      //for path formation
            }
        }
        vs[i->sn]=1;
        s.erase(*i);
    }

    return min(d2[n-1],d1[n-1]);
    //return pr;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll> > > v(n);int x,y;ll wt;
    for(int i=0;i<m;i++){
        cin>>x>>y>>wt;
        v[x-1].pb(mp(y-1,wt));
        //v[y-1].pb(mp(x-1,wt));
    }

    cout<<dikst(v)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    //precomp();
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}