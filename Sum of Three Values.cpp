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
    int n,x;cin>>n>>x;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].fs;
        v[i].sn=i;
    }

    if(n<3){cout<<"IMPOSSIBLE\n";return;}

    sort(v.begin(),v.end());

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int y=x-v[i].fs-v[j].fs;
            auto f=lower_bound(v.begin()+j+1,v.end(),mp(y,0));
            if(f->fs==y){
                printf("%d %d %d\n",v[i].sn+1,v[j].sn+1,(f->sn)+1);
                return;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}