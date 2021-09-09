#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

//void precomp(){}

void solve(){
    int n;cin>>n;
    vector<vector<int> > v(n);int p;
    for(int i=1;i<n;i++){
        cin>>p;
        v[--p].pb(i);
    }

    vector<int> res(n,1);
     
    function <void(int)> dfs = [&](int r){
        for(auto i: v[r]){
            dfs(i);
            res[r]+=res[i];
        }
        return;
    };
    
    dfs(0);

    for(auto i: res)cout<<i-1<<" ";
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