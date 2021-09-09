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
const ll pinf = 1ll<<62, ninf = -1ll*(pinf);
 
//void precomp(){}
 
void solve(){
    int n,x;cin>>n>>x;
    map<int,set<int> > m1;
    int in;
    for(int i=0;i<n;i++){
        cin>>in;
        m1[in].insert(i+1);
    }

    for(auto& i: m1){
        auto& j = i.sn;
        while(j.size()){
            int pj=*j.begin();
            j.erase(j.begin());
            if(m1[x-i.fs].size()){
                cout<<pj<<" "<<*(m1[x-i.fs].begin())<<"\n";
                m1[x-i.fs].erase(m1[x-i.fs].begin());
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