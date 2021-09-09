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
    string s;cin>>s;
    map<char,int> m1;
    for(auto i: s)m1[i]++;
    int o=0;char x;
    for(auto i: m1)if(i.sn&1){o++;x=i.fs;}

    if(s.size()&1 && o==1){
        m1[x]--;
        for(auto i=m1.begin();i!=m1.end();i++){
            int y=i->sn;
            while(y/2<(i->sn)){cout<<i->fs;i->sn--;}
        }
        cout<<x;
        for(auto i=m1.rbegin();i!=m1.rend();i++){
            while(i->sn){cout<<i->fs;i->sn--;}
        }
        cout<<"\n";
    }

    else if(!(s.size()&1) && o==0){ 
        for(auto i=m1.begin();i!=m1.end();i++){
            int y=i->sn;
            while(y/2<(i->sn)){cout<<i->fs;i->sn--;}
        }
        for(auto i=m1.rbegin();i!=m1.rend();i++){
            while((i->sn)--){cout<<i->fs;i->sn--;}
        }
        cout<<"\n";
    }

    else cout<<"NO SOLUTION\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}