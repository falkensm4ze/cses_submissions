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

set<string> s;
string s1;
int n;

void func(int pos,set<int> spos,string tmp){
    if(spos.size()==1 || pos==n-1){
        tmp[*spos.begin()]=s1[pos];
        s.insert(tmp);
        tmp=s1;
        return;
    }
    for(auto i: spos){
        auto tmp1=tmp;
        auto spos1 = spos;
        tmp1[i]=s1[pos];
        spos1.erase(i);
        func(pos+1,spos1,tmp1);
    }
    return;
}  

void solve(){
    cin>>s1;
    n=s1.size();
    set<int> spos;
    for(int i=0;i<n;i++)spos.insert(i);
    func(0,spos,s1);
    cout<<s.size()<<"\n";
    for(auto i: s){
        cout<<i<<"\n";
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