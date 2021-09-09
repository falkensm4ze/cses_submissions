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
    vector<pair<pair<int,int>,pair<ll,ll> > > v(n+1);
    v[0]=mp(mp(0,0),mp(0,0));
    for(int i=1;i<n+1;i++){
        cin>>v[i].fs.fs>>v[i].fs.sn>>v[i].sn.fs;
        v[i].sn.sn=v[i].sn.fs;
    }
    sort(v.begin(),v.end());
    int p[n+1]={0};ll mx=0;
    for(int i=0;i<n+1;i++){
        if(i){
            if(v[i].sn.fs+v[p[i-1]].sn.sn > v[i].sn.sn){
                p[i]=p[i-1];
                v[i].sn.sn = v[i].sn.fs+v[p[i]].sn.sn;
            }
        }
        amax(mx,v[i].sn.sn);
        auto j=lower_bound(v.begin()+(i+1),v.end(),mp(mp(v[i].fs.sn+1,v[i].fs.sn+1),mp(0ll,0ll)));
        if(j!=v.end()){
            if(j->sn.sn <= v[i].sn.sn+j->sn.fs){
                j->sn.sn = j->sn.fs+v[i].sn.sn;
                p[(int)(j-v.begin())]=i;
            }
        }
    }

    cout<<mx<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}