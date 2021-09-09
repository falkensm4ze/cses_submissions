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
 
struct dsu{    
    vector <int> p;
    dsu(int n){p=vector<int>(n,-1);}
    void unite(int u,int v){
    	if(check(u,v))return;
        u=root(u);v=root(v);
        if(u!=v){p[u]+=p[v];p[v]=u;}
    }
    int root(int x){if(p[x]<0)return x;p[x]=root(p[x]);return p[x];}
    bool check(int u,int v){return (root(u)==root(v));}
};

void solve(){
	int n,m;cin>>n>>m;
	dsu d1(n);int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;a--;b--;
		d1.unite(a,b);
	}

	a=-1;vector<int> v;

	for(int i=0;i<d1.p.size();i++){
		if(d1.p[i]<0){
			if(a<0)a=i+1;
			else v.pb(i+1);
		}
	}

	cout<<v.size()<<"\n";
	for(auto i: v){
		cout<<a<<" "<<i<<"\n";
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}