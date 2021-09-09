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
const ll inf = 1ll<<61;
 
//void precomp(){}
 
void solve(){
	int n,a,b;cin>>n>>a>>b;
	ll x[n];scanv(x);
	ll ps[n+1]={0};
	for(int i=1;i<n+1;i++)ps[i]=ps[i-1]+x[i-1];
	set<ll> s;map<ll,int> m;
    for(int i=a;i<b;i++){
    	s.insert(ps[i]);
    	m[ps[i]]++;
    }
 
    ll mx=-inf;
	for(int i=0,r1=a,r2=b;r1<n+1;i++,r1++,r2++){
		if(r2<n+1){
			s.insert(ps[r2]);
			m[ps[r2]]++;
		}
		auto j = s.end();j--;
		amax(mx,*j-ps[i]);
		if((--m[ps[r1]])==0){
			s.erase(ps[r1]);
		}
	}
 
	cout<<mx<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}