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
#define uset(T) unordered_set<T>
#define umap(T1,T2) unordered_map<T1,T2>
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
const ll inf = 1e17+7ll;

typedef struct {
    ll d;
    int fr;
    int mnf;
    int mxf;
} invob;

const invob tmp = {.d=inf,.fr=0,.mnf=mod,.mxf=0,};
 
//void precomp(){}

invob djkst(vector<vector<pair<int,ll> > > &g){
    int n=g.size();
    vector<invob> res(n,tmp);
    res[0]={.d=0,.fr=1,.mnf=0,.mxf=0};
    set<pair<ll,int> > s;vector<bool> vs(n,0);

    for(int i=0;i<n;i++){
        s.insert(mp(res[i].d,i));
    }
    
    while(s.size()){
        auto i = s.begin();
    
        if(i->fs==inf)break;
        for(auto j: g[i->sn]){  
            
            ll dis = i->fs+j.sn;
            int cur = j.fs, prev = i->sn;

            if(vs[j.fs])continue;
            else if(res[cur].d==dis){
                res[cur].fr+=res[prev].fr;
                s.insert(mp(dis,cur));
                amin(res[cur].mnf,res[prev].mnf+1);
                amax(res[cur].mxf,res[prev].mxf+1);
            }
            else if(res[cur].d>dis){
                s.erase(mp(res[cur].d,cur));
                s.insert(mp(dis,cur));
                res[cur].d=dis;
                res[cur].fr=res[prev].fr;
                res[cur].mnf=res[prev].mnf+1;
                res[cur].mxf=res[prev].mxf+1;
            }
        }
    
        vs[i->sn]=1;
        s.erase(*i);
    }
    
    return res[n-1];
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,ll> > > v(n);int x,y,c;
    for(int i=0;i<m;i++){
        cin>>x>>y>>c;
        v[x-1].pb(mp(y-1,c));
    }

    invob res = djkst(v);

    cout<<res.d<<" "<<res.fr<<" "<<res.mnf<<" "<<res.mxf<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    //precomp();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // time_t start,end;
    // time(&start);
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    // time(&end);

    // double time_taken = double(end-start);
    // cout<<"Time taken by program is : "<<fixed<<time_taken<<setprecision(5)<<" sec.\n";
    
    return 0;
}