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
		t=vector<T>(nseg<<1);  
	}
	void build(){
		for(int i=nseg-1;i>0;--i){
			t[i]=t[i<<1]+t[i<<1|1];
		}
	}
	void modify(int p,T value){
		for(t[p+=nseg]=value;p>1;p>>=1){
			t[p>>1]=t[p]+t[p^1];
		}
	}
	T query(int l,int r){
		T res=0;
		for(l+=nseg,r+=nseg;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};
 
void solve(){
	int n;cin>>n;
	int a[n];scanv(a);
	segtree<int> s(n);
	vec(int) p(n,1);
	for(int i=0;i<n;i++){
		s.t[i+n]=1;
	}
	s.build();

	for(int i=0;i<n;i++){
		int x,l=0,r=n-1,m=(l+r)>>1;cin>>x;
		while(l<r){
			int qx=s.query(0,m+1);
			if(qx>x){
				r=m-1;
			}
			else if(qx<x){
				l=m+1;
			}
			else if(p[m]==0){
				r=m-1;
			}
			else break;
			m=(l+r)>>1;
		}
		cout<<a[m]<<" ";
		p[m]=0;
		s.modify(m,0);
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