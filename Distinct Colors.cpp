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
    int n;cin>>n;
    auto c=vec(int)(n,0);
    scanv(c);
    vector<vector<int> > v(n);int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
    }

    auto vs=vec(bool)(n,0);
    auto res=vec(int)(n,0);      
    function <unordered_set<int>(int)> dfs = [&](int r){
        vs[r]=1;
        unordered_set<int> s;s.insert(c[r]);
        for(auto i: v[r]){
            if(!vs[i]){
                auto si=dfs(i);
                if(s.size()>si.size())swap(s,si);
                s.insert(si.begin(),si.end());
            }
        }
        res[r]=s.size();
        return s;
    };
    dfs(0);

    printv(res);
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}