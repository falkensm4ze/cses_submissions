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
#define ast(v,n) assert(v.size()==n)
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}
 
int mul(int x, int y){
    return (x * 1ll * y) % mod;
}
 
int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
int inv(int x){
    return binpow(x, mod - 2);
}
 
int divide(int x, int y){
    return mul(x, inv(y));
}
 
vector<vector<int> > mtmul(vector<vector<int> > &x,vector<vector<int> > &y){
    assert(x.size()==6 && x[0].size()==6);
    assert(y.size()==6 && y[0].size()==6);
    vector<vector<int> > z(6,vector<int>(6,0));

    for(int i=0;i<6;i++){
    	for(int j=0;j<6;j++){
    		for(int k=0;k<6;k++){
    			z[j][k]=add(z[j][k],mul(x[j][i],y[i][k]));
    		}
    	}
    }

    return z;
}

vector<vector<int> > mtpow(vector<vector<int> > x,ll y){
	vector<vector<int> > z(6,vector<int>(6,0));
	for(int i=0;i<6;i++)z[i][i]=1;
	if(y<=0){
		return z;
	}
    while(y){
        if(y & 1ll) z = mtmul(z,x);
        x = mtmul(x, x);
        y >>= 1ll;
    }
    return z;
}

void solve(){
	ll n;cin>>n;
	vector<vector<int> > cf = {{0,1,0,0,0,0},
	                           {0,0,1,0,0,0},
	                           {0,0,0,1,0,0},
	                           {0,0,0,0,1,0},
	                           {0,0,0,0,0,1},
	                           {1,1,1,1,1,1}};

	assert(cf.size()==6 && cf[0].size()==6);

	vector<int> v = {1,2,4,8,16,32};
	if(n<=6){
		cout<<v[n-1]<<"\n";
		return;
	}
	cf = mtpow(cf,n-6ll);
	int ans=0;
	for(int i=0;i<6;i++){
		ans=add(ans,mul(cf[5][i],v[i]));
	}
	cout<<cor(ans)<<"\n";
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