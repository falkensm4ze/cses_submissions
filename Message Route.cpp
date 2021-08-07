#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back

typedef int64_t ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
	int n,m;cin>>n>>m;
	vector <int> v[n];int x,y;
	for(int i=0;i<m;i++)
	{
	    cin>>x>>y;
	    v[x-1].emplace_back(y-1);
	    v[y-1].emplace_back(x-1);
	}

	function <void(int)> dfs = [&](int r){
		for(auto i: v[r]){
		    
		}
		return;
	};

	function<vector<int>(int)> bfs = [&](int r){
		queue<int> q;q.push(r);
	    vector<int> d(n,mod);d[0]=0;
		while(!q.empty()){
			for(auto& i: v[q.front()]){
				if(d[i]==mod){
					q.push(i);
					d[i]=1+d[q.front()];
				}
			}
			q.pop();
		}
		
		vector<int> path(0);
		if(d[n-1]==mod)return path;
        r=n-1;path.pb(r);
		while(r){
			for(auto i: v[r]){
				if(d[i]==d[r]-1){
					r=i;break;
				}
			}
			path.pb(r);
		}		  

		reverse(path.begin(),path.end());
		return path;
	};
    
    auto d=bfs(0);
	if(d.size()==0)cout<<"IMPOSSIBLE\n";
	else {
		cout<<d.size()<<"\n";
		for(auto i: d){
			cout<<i+1<<" ";
		}
		cout<<"\n";
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