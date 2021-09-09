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
    int n;cin>>n;
    int X[n];for(auto& i: X)cin>>i;
 
    int L=0;
    int M[n+1]={0};M[0]=-1;
 
    for(int i=0;i<n;i++){
        int lo = 1;
        int hi = L;
        while (lo<=hi){
            int mid = ceil((lo+hi)/2);
            if(X[M[mid]] <= X[i])lo = mid+1;
            else hi = mid-1;
        }
 
        int newL = lo;
        M[newL] = i;
            
        if(newL>L)L = newL;
    }
 
    cout<<L<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}