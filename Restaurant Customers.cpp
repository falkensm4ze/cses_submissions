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
    vector<pair<int,int> > stmp;
    int mx=0;int s,e;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        stmp.pb(mp(s,0));
        stmp.pb(mp(e,1));
    }
    sort(stmp.begin(),stmp.end());
    map<int,int> m1;m1[0]=0;

    for(auto i: stmp){
        auto j = m1.lower_bound(i.fs);j--;
        if(!i.sn)
            m1[i.fs]=1+j->sn;
        else 
            m1[i.fs]=j->sn-1;

        //cout<<i.fs<<" "<<m1[i.fs]<<"\n";
    }

    for(auto i: m1){
        //cout<<i.fs<<" "<<i.sn<<"\n";
        amax(mx,i.sn);
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