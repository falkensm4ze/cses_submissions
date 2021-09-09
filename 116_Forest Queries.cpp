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
	int n,q;cin>>n>>q;
	int pr[n+1][n+1];memset(pr,0,sizeof(int)*(n+1)*(n+1));
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<n;j++)if(s[i][j]=='*')pr[i+1][j+1]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			pr[i][j]+=pr[i][j-1];
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			pr[i][j]+=pr[i-1][j];
		}
	}

	while(q--){
		int x1,y1,x2,y2;cin>>y1>>x1>>y2>>x2;
		x1--;y1--;
		int ans = pr[y2][x2]+pr[y1][x1]-pr[y1][x2]-pr[y2][x1];
		cout<<ans<<"\n";
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