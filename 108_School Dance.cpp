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
const ll inf = 1e9+7;
 
//void precomp(){}
 
void solve(){
	int n,n1,n2,m;
	cin>>n1>>n2>>m;
	n=n1+n2+2;

	vector<vector<ll> > cap;
	cap = vector<vector<ll> >(n,vector<ll>(n,0));
	
	vector<vector<int> > v(n);
	int x,y,s=0,t=n-1;ll c=0;
	    
	for(int i=0;i<m;i++){
	    cin>>x>>y;
	    v[x].pb(n1+y);
	    v[n1+y].pb(x);
	    cap[x][n1+y]=1;
	}

	for(int i=1;i<n-1;i++){
		if(i<=n1){
			v[0].pb(i);
			v[i].pb(0);
			cap[0][i]=1;
		}
		else {
			v[n-1].pb(i);
			v[i].pb(n-1);
			cap[i][n-1]=1;
		}
	}

	ll mxflow = 0;
	 
	while(1){
	   	queue<int> q;vector<int> prt(n,-1);
	   	q.push(s);bool f = 0;prt[s]=s;	    
	    	
	   	while(!q.empty()){
	   		int x = q.front();
	   		q.pop();
	   		for(auto i: v[x]){
	   		    if(cap[x][i]>0 && prt[i]==-1){
	   		        q.push(i);
	   		        prt[i]=x;
	  		        if(i==t)f=1;
	   		    }
	  		}
	   		if(f)break;
	   	}
	   	
	   	if(f){
	   		int i=t;ll bottleneck=inf;
	   		while(i!=s){
	   			amin(bottleneck,cap[prt[i]][i]);
	   			i=prt[i];
	   		}
	   		i=t;
	   		while(i!=s){
	   			cap[prt[i]][i]-=bottleneck;
	   			cap[i][prt[i]]+=bottleneck;
	    		i=prt[i];
	    	}
	  		mxflow += bottleneck;
	   	}
	 
	    else break;
	}

	cout<<mxflow<<"\n";

	for(int i=1;i<n1+1;i++){
		for(int j=n1+1;j<n-1;j++){
			if(cap[i][j]==0 && cap[j][i]==1){
				cout<<i<<" "<<j-n1<<"\n";
			}
		}
	}
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