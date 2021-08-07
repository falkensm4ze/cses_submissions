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
 
void solve(){
	ll n,k;cin>>n>>k;
	vec(int) x(n);
	scanv(x);

	ll l=0,r=0;set<int> s;map<int,int> m;
	ll cr=0;
	for(l=0,r=0;l<=r && r<n;){
		if(s.size()==k && m[x[r]]==0){
			--m[x[l]];
			if(m[x[l]]==0)s.erase(x[l]);
			++l;
			continue;
		}
		s.insert(x[r]);
		++m[x[r]];
		cr+=r-l+1ll;
		++r;
	}
	cout<<cr<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}