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
    int n,m;cin>>n>>m;
    vector<int> v(n),pos(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
        pos[--v[i]]=i;
    }

    int c=1;
    for(int i=1;i<n;i++){
        if(pos[i]<pos[i-1])c++;
    }

    //cout<<c<<"\n";
    set<pair<int,int> > s;

    while(m--){
        int p1,p2;
        cin>>p1>>p2;--p1,--p2;

        if(v[p1]>0)s.insert(mp(v[p1],v[p1]-1));
        if(v[p2]>0)s.insert(mp(v[p2],v[p2]-1));
        if(v[p1]<n-1)s.insert(mp(v[p1]+1,v[p1]));
        if(v[p2]<n-1)s.insert(mp(v[p2]+1,v[p2]));

        for(auto i: s){
            if(pos[i.fs]<pos[i.sn])c--;
        }

        swap(pos[v[p1]],pos[v[p2]]);
        swap(v[p1],v[p2]);

        for(auto i: s){
            if(pos[i.fs]<pos[i.sn])c++;
        }

        cout<<c<<"\n";
        s.clear();
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