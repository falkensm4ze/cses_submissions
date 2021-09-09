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

vector<pair<int,int> > v;
int c=0;

void func(int s,int d, int m){
    if(!m)return;
    func(s,6-s-d,m-1);
    v.pb(mp(s,d));
    c++;
    func(6-s-d,d,m-1);
    return;
}
  
void solve(){
    int n;cin>>n;
    func(1,3,n);
    printf("%d\n",c);
    for(auto i: v){
        printf("%d %d\n",i.fs,i.sn);
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