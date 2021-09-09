#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
 
typedef int64_t ll;

const int mod = 1e9+7;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 
 
//void precomp(){}

struct dsu{    
    vector <int> p;
    dsu(int n){p=vector<int>(n,-1);}
    int root(int x){if(p[x]<0)return x;p[x]=root(p[x]);return p[x];}
    bool check(int u,int v){return (root(u)==root(v));}
    void unite(int u,int v){
    	if(check(u,v))return;
        u=root(u);v=root(v);
        if(u!=v){p[u]+=p[v];p[v]=u;}
    }
};
 
void solve(){
	unsigned n,m;cin>>n>>m;
    string s[n];
    for(auto& i: s){
    	cin>>i;
    	assert(i.size()==m);
    }
    dsu d1(n*m);int wall=0,room=0;
    for(int i=0;i<n*m;i++){
    	int r=i/m,c=i%m;
    	if(s[r][c]=='#'){wall++;continue;}
    	if(r>0 && s[r-1][c]!='#')d1.unite(i,i-m);
    	if(r<n-1 && s[r+1][c]!='#')d1.unite(i,i+m);
    	if(c>0 && s[r][c-1]!='#')d1.unite(i,i-1);
    	if(c<m-1 && s[r][c+1]!='#')d1.unite(i,i+1);
    }
    
    for(auto i: d1.p){
        if(i<0)room++;
    }
    room-=wall;
    cout<<room<<"\n";
}
 
int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    //precomp();
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}