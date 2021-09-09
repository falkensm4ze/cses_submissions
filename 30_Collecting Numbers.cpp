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
    vector<int> pos(n);

    for(int i=0;i<n;i++){
        int x;cin>>x;
        pos[--x]=i;
    }

    int c=0;
    for(int i=1;i<n;i++){
        if(pos[i]<pos[i-1])c++;
    }

    cout<<c+1<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}