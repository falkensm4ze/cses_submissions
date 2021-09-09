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
int k;
//void precomp(){}

vector<ll> dikst(vector<vector<pair<int,ll> > > &g){
    
    int n=g.size();
    
    priority_queue<pair<ll,int> > s;
    vector<int> ct(n,0);
    vector<vector<ll> > d(n,vector<ll>(k,inf));

    for(int i=0;i<k;i++)d[0][i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            s.push(mp(-d[i][j],i));
        }
    }

    ct[0]=k-1;
    
    while(ct[n-1]<k){
        
        if(s.empty())break;
        pair<ll,int> i = s.top();
        s.pop();

        //cout<<i.fs<<" "<<i.sn<<"\n";

        if(ct[i.sn]>=k){
            continue;
        }
        
        d[i.sn][ct[i.sn]++]=-(i.fs);
        
        for(auto j: g[i.sn]){
            if(ct[j.fs]>=k)continue;
            s.push(mp((i.fs-j.sn),j.fs));
        }
    }
    
    return d[n-1];
}

void solve(){
    int n,m;
    cin>>n>>m>>k;
    vector<vector<pair<int,ll> > > v(n);int x,y;ll wt;
    for(int i=0;i<m;i++){
        cin>>x>>y>>wt;
        v[x-1].pb(mp(y-1,wt));
        //v[y-1].pb(mp(x-1,wt));
    }

    vector<ll> dk = dikst(v);
    printv(dk);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    //precomp();
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}