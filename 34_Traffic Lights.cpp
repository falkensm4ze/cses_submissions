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
    int n,x;cin>>x>>n;set<int> s;multiset<int> d;
    s.insert(0);s.insert(x);
    d.insert(x);
    for(int i=0;i<n;i++){
        cin>>x;
        auto j = s.lower_bound(x);
        auto k=j--;
        d.erase(d.find(*(k)-*(j)));
        s.insert(x);
        d.insert(x-*(j));
        d.insert(*(k)-x);
        
        cout<<*(--d.end())<<" ";
    }
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