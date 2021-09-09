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
    int n,m,k;cin>>n>>m>>k;
    int a[n],b[m];
    for(auto& i: a)cin>>i;
    for(auto& i: b)cin>>i;
    sort(a,a+n);
    sort(b,b+m);
    int c=0;
    for(int i=0,j=0;i<n && j<m;){
        //cout<<b[j]-a[i]<<" ";
        if(abs(b[j]-a[i])<=k){
            j++;i++;c++;
        }
        else if(b[j]>a[i]){
            i++;
        }
        else {
            j++;
        }
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