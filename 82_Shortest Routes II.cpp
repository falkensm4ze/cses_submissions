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
const ll inf = 1e15+7ll;
 
//void precomp(){}

void solve(){
	int n,m,q;cin>>n>>m>>q;
    vec(vec(ll)) d(n,vec(ll)(n,inf));
    for(int i=0;i<m;i++){
        int x,y;ll c;cin>>x>>y>>c;
        x--;y--;
        amin(d[x][y],c);
        amin(d[y][x],c);
    }

    for(int i=0;i<n;i++){
        d[i][i]=0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                amin(d[i][j],d[i][k]+d[k][j]);
                amin(d[j][i],d[j][k]+d[k][i]);
            }
        }
    }

    while(q--){
        int x,y;cin>>x>>y;
        if(d[x-1][y-1]==inf){
            cout<<-1<<"\n";
        }
        else {
            cout<<d[x-1][y-1]<<"\n";
        }
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