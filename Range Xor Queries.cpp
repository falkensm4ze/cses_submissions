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
 
//void precomp(){}

template <typename T> struct segtree {     
	int nseg;
	vector<T> t;
	segtree(int n){
		nseg=n;
		t=vector<T>(nseg<<1,0);  
	}
	void build(){
		for(int i=nseg-1;i>0;--i){
			t[i]=(t[i<<1]^t[i<<1|1]);
		}
	}
	void modify(int p,T value){
		for(t[p+=nseg]=value;p>1;p>>=1){
			t[p>>1]=(t[p]^t[p^1]);
		}
	}
	T query(int l,int r){
		T res=0;
		for(l+=nseg,r+=nseg;l<r;l>>=1,r>>=1){
			if(l&1)res=res^t[l++];
			if(r&1)res=res^t[--r];
		}
		return res;
	}
};
 
void solve(){
	int n,m;cin>>n>>m;
	vector<segtree<int> > a(32,segtree<int>(n));
	for(int i=0;i<n;i++){
		int x;cin>>x;int j=0;
		for(int j=0;j<32;j++){
			a[j].t[i+n]=(x>>j)&1;
		}
	}
	for(int i=0;i<32;i++)a[i].build();
	for(int i=0;i<m;i++){
		int l,r;cin>>l>>r;
		l--;int x=0;
		for(int i=31;i>=0;i--){x<<=1;x+=a[i].query(l,r);}
		cout<<x<<"\n";
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