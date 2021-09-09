#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
 
typedef int64_t ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){

    int n,m;cin>>n>>m;
    vector <int> v[n];int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        v[x-1].emplace_back(y-1);
        v[y-1].emplace_back(x-1);
    }

    vector<int> vs(n,0),p(n,0),c;bool f=0;
      
    function <int(int)> dfs = [&](int r){
        vs[r]=1;
        for(auto i: v[r]){
            if(i==p[r])continue;
            else {
                p[i]=r;
                if(vs[i]==1){
                    c.pb(i);
                    c.pb(r);
                    f=1;
                    return i;
                }
                else {
                    int res=dfs(i);
                    if(res>=0){
                        c.pb(r);
                        f=1;
                        if(res==r)return -1;
                        else return res;
                    }
                    else if(f){
                        return -1;
                    }
                }
            }
        }
        return -1;
    };
    
    for(int i=0;i<n;i++){
        if(vs[i])continue;
        else if(c.size()>=4)break;
        x=dfs(i);
    }

    if(c.size()==0)cout<<"IMPOSSIBLE\n";
    else {
        cout<<c.size()<<"\n";
        for(auto i: c)cout<<i+1<<" ";
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