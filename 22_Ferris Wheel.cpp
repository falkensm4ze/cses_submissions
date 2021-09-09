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
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];a[i]*=-1;
    }
    sort(a.begin(),a.end());
    vector<bool> vs(n,0);set<pair<int,int> > s;int c=0;
    for(int i=0;i<n;i++){
        s.insert(mp(a[i],i));
    }
    for(int i=0;i<n;i++){
        if(vs[i])continue;
        auto j = s.lower_bound(mp(max(-1*(x-abs(a[i])),a[i]),i+1));
        if(j!=s.end()){
            vs[j->sn]=1;
            s.erase(j);
            s.erase(mp(a[i],i));
        }
        c++;vs[i]=1; 
    }

    cout<<c<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}