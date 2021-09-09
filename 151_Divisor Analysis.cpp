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
 
const ll mod = 1e9+7ll;
 
//void precomp(){}
 
ll add(ll x,ll y){
    x+=y;
    while(x>=mod)x-=mod;
    while(x<0)x+=mod;
    return x;
}
 
ll mul(ll x,ll y){
    x%=mod;
    y%=mod;
    return (x*y)%mod;
}
 
ll binpow(ll x,ll y){
    ll z=1ll;
    while(y){
        if(y&1ll)z=mul(z,x);
        x=mul(x,x);
        y>>=1ll;
    }
    return z;
}
 
ll inv(ll x){
    return binpow(x,mod-2ll);
}
 
ll divide(ll x,ll y){
    return mul(x,inv(y));
}
 
void solve(){
    int n;cin>>n;
    ll x,k;
    ll sum=1ll,num=1,num2=1,pd=1;
 
    function<ll(ll,ll)> f = [&](ll a,ll b){
        return divide((binpow(a,b+1ll)-1ll),a-1ll);
    };
 
    for(int i=0;i<n;i++){
        cin>>x>>k;
        sum=mul(sum,f(x,k));
        pd=mul(binpow(pd,k+1ll),binpow(binpow(x,(k*(k+1ll))/2ll),num2));
        num=mul(num,k+1ll);
        num2 = (num2*(k+1ll))%(mod-1);
    }
 
    sum = cor(sum);
    pd = cor(pd);
    num = cor(num);
 
    cout<<num<<" "<<sum<<" "<<pd<<"\n"; 
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
 
    //precomp();
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    // time_t start,end;
    // time(&start);
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    // time(&end);
 
    // double time_taken = double(end-start);
    // cout<<"Time taken by program is : "<<fixed<<time_taken<<setprecision(5)<<" sec.\n";
    
    return 0;
}