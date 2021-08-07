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
    int l,r,n;
    cin>>n;

    vector<pair<pair<int,int>,pair<int,int> > > v(n);    
    for(int i=0;i<n;i++){
        cin>>l>>r;
        v[i]=mp(mp(l,r),mp(i,0));
    }

    sort(v.begin(),v.end(),[](pair<pair<int,int>,pair<int,int> >& x,pair<pair<int,int>,pair<int,int> >& y){
        if(x.fs.fs==y.fs.fs)return x.fs.sn<y.fs.sn;
        return x.fs.fs<y.fs.fs;
    });
    
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p;
    int mx=0;
    
    for(int i=0;i<n;i++){
        if(!p.empty()){
            if(p.top().fs<v[i].fs.fs){
                v[i].sn.sn=v[p.top().sn].sn.sn;
                p.pop();
            }
            else {
                v[i].sn.sn=p.size()+1;
                amax(mx,v[i].sn.sn);
            }
        }
        else {
            v[i].sn.sn=p.size()+1;
            amax(mx,v[i].sn.sn);
        }
        p.push(mp(v[i].fs.sn,i));
    }

    sort(v.begin(),v.end(),[](pair<pair<int,int>,pair<int,int> >& x,pair<pair<int,int>,pair<int,int> >& y){
        return x.sn.fs<y.sn.fs;
    });

    cout<<mx<<"\n";
    for(auto i: v)cout<<i.sn.sn<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}