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
    int n,m;cin>>n>>m;
    multiset<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.insert(x);
    }
 
    for(int i=0;i<m;i++){
        int x;cin>>x;
        auto j = a.lower_bound(x);
        if(*j==x){
            cout<<*j<<"\n";
            a.erase(j);
        }
        else if(j!=a.begin()){
            --j;
            cout<<*j<<"\n";
            a.erase(j);
        }
        else {
            cout<<"-1\n";
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