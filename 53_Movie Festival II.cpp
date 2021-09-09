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
    int n,k;cin>>n>>k;
    vector<pair<int,int> > v(n);
    multiset<int> sc;

    for(int i=0;i<n;i++){
    	cin>>v[i].fs>>v[i].sn;
    }

    sort(v.begin(),v.end(),[](pair<int,int>&x,pair<int,int>&y){
    	if(x.sn==y.sn)return x.fs<y.fs;
    	return x.sn<y.sn;
    });

    for(int i=0;i<k;i++){
    	sc.insert(0);
    }

    int mxv=0;
    for(int i=0;i<n;i++){
    	auto j=sc.upper_bound(v[i].fs);
    	if(j!=sc.begin()){
    		sc.erase(--j);
    		sc.insert(v[i].sn);
    		mxv++;
    	}
    }

    cout<<mxv<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    solve();    
    return 0;
}