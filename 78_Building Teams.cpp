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
    
    vector<int> res(n,0);
    
    for(int itr=0;itr<n;itr++){
        if(res[itr]==0){
            queue<int> q;
            q.push(itr);res[itr]=1;
                
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for(auto i : v[x]){
                    if(res[i]==0){
                        res[i]=3-res[x];
                        q.push(i);
                    }
                    else if(res[i]==res[x]){
                        cout<<"IMPOSSIBLE\n";return;
                    }
                }
            }
        }
    }

    for(auto i: res)cout<<i<<" ";
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