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

    int n;cin>>n;
    vector<int> v[n];int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].emplace_back(y-1);
        v[y-1].emplace_back(x-1);
    }

    vector<int> d;
    
    function <int(int)> bfs = [&](int r){
        
        queue<int> q;
        q.push(r);

        d = vector<int>(n,0);d[r]=1;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto j: v[i]){
                if(!d[j]){
                    d[j] = d[i] + 1;
                    q.push(j);
                }
            }
        }

        int in=0;        
        for(int i=0;i<n;i++)if(d[in]<d[i])in=i;
        return in;
    };

    x = bfs(bfs(0));
    cout<<d[x]-1<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}