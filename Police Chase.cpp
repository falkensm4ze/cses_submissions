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
const ll inf = 1e9+7;

struct dsu{    
    vector <int> p;
    dsu(int n){p=vector<int>(n,-1);}
    void unite(int u,int v){
        u=root(u);v=root(v);
        if(u!=v){p[u]+=p[v];p[v]=u;}
    }
    int root(int x){if(p[x]<0)return x;p[x]=root(p[x]);return p[x];}
    bool check(int u,int v){return (root(u)==root(v));}
};
 
//void precomp(){}
 
void solve(){
	int n,m;cin>>n>>m;
    
    vector<vector<ll> > cap;
    cap = vector<vector<ll> >(n,vector<ll>(n,0));
 
    vector<vector<int> > v(n);
    int x,y,s=0,t=n-1;

    vector<pair<int,int> > edges;    
    for(int i=0;i<m;i++){
        cin>>x>>y;
        edges.pb(mp(x-1,y-1));
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
        cap[x-1][y-1]=1;
        cap[y-1][x-1]=1;
    }
 
    ll mxflow = 0;
 
    while(1){
    	queue<int> q;vector<int> prt(n,-1);
    	q.push(s);bool f = 0;prt[s]=s;	    
    	
    	while(!q.empty()){
    		int x = q.front();
    		q.pop();
    		for(auto i: v[x]){
    		    if(cap[x][i]>0 && prt[i]==-1){
    		        q.push(i);
    		        prt[i]=x;
    		        if(i==t)f=1;
    		    }
    		}
    		if(f)break;
    	}
    	
    	if(f){
    		int i=t;ll bottleneck=mod;
    		while(i!=s){
    			amin(bottleneck,cap[prt[i]][i]);
    			i=prt[i];
    		}
    		i=t;
    		while(i!=s){
    			cap[prt[i]][i]-=bottleneck;
    			//cap[i][prt[i]]+=bottleneck;
    			i=prt[i];
    		}
    		mxflow += bottleneck;
    	}
 
    	else break;
    }

	vector<bool> vs(n,0);  
	function <void(int)> dfs = [&](int r){
	    vs[r]=1;
		for(auto i: v[r]){
		    if(!vs[i] && cap[r][i]){
		        dfs(i);
		    }
		}
		return;
	};
	dfs(s);
	dsu d(n);
	for(int i=0;i<n;i++){
		if(vs[i])d.unite(s,i);
		else d.unite(t,i);
	}

	cout<<mxflow<<"\n";

	for(auto i: edges){
		if(d.root(i.fs)!=d.root(i.sn)){
			cout<<i.fs+1<<" "<<i.sn+1<<"\n";
			--mxflow;
		}
		if(mxflow==0)break;
	}
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