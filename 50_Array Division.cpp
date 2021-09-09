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

const ll mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
	ll n,k;cin>>n>>k;
	vec(ll) a(n);
	scanv(a);

	ll l=mod,r=0;
	for(auto i: a){r+=i;amin(l,i);}

	function<bool(ll)> check = [&](ll mid){
		int groups = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > mid) {
				return false;
			}
			if (sum + a[i] > mid) {
				++groups;
				sum = 0;
			}
			sum += a[i];
		}
		if (sum > 0) {
			++groups;
		}
		return groups <= k;
	};

	while(r>l){
		ll m = (l+r)>>1;
		if(check(m)){
			r=m;
		}
		else {
			l=m+1ll;
		}
	}

	cout<<((l+r)>>1)<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}