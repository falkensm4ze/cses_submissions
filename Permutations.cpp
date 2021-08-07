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

const int mod = 1e9+7;
 
//void precomp(){}
 
void solve(){
    int n;cin>>n;
    if(n==2 || n==3)cout<<"NO SOLUTION\n";
    else if(n==1){
        cout<<"1\n";
    }
    else if(n==4){
        cout<<"2 4 1 3\n";
    }
    else {
        for(int i=n,j=(n+1)/2,c=n;c>0;c--){
            if(c&1){cout<<j<<" ";j--;}
            else {cout<<i<<" ";i--;}
        }

        cout<<"\n";
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