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

const int mod = 1e9+7;
 
//void precomp(){}

struct compressed {
    vector<pair<pair<int,int>,int> > civ;
    int sz;
    compressed(vector<pair<pair<int,int>,int> > &iv){
        map<int,int> cr;
        civ=iv;
        for(auto i: civ){
            cr[i.fs.fs]=0;
            cr[i.fs.sn]=0;
        }
        int c=0;
        for(auto& i: cr){
            i.sn=c++;
        }
        for(auto& i: civ){
            i.fs.fs=cr[i.fs.fs];
            i.fs.sn=cr[i.fs.sn];
        }
        sz=c;
    }
};

template <typename T> struct fenwik {
    vector<T> tr;int n;
    fenwik(int nf){
        n=nf;tr.assign(nf,T(0));
    }
    fenwik(vector<int> a) : fenwik(a.size()){
        for(int i=0;i<a.size();i++){
            add(i,T(a[i]));
        }
    }
    T sum(int r) {
        T ret = 0;
        for(;r>=0;r=(r&(r+1))-1){
            ret+=tr[r];
        }
        return ret;
    }
    void add(int r,T x) {
        for (;r<n;r=r|(r+1)){
            tr[r]+=x;
        }
    }
};

void solve(){
    int n;cin>>n;
    vector<pair<pair<int,int>,int> >r(n);
    for(int i=0;i<n;i++){
        r[i].sn=i;
        cin>>r[i].fs.fs>>r[i].fs.sn;
    }

    compressed cr(r);

    //cout<<cr.sz<<"\n";

    fenwik<int> f1(cr.sz),f2(cr.sz);
    vector<int> v1(n,0),v2(n,0);

    int c=0;
    sort(cr.civ.begin(),cr.civ.end(),
        [&](pair<pair<int,int>,int> &x,
            pair<pair<int,int>,int> &y
        ){
        if(x.fs.fs==y.fs.fs)return x.fs.sn>y.fs.sn;
        return x.fs.fs<y.fs.fs;
    });
    
    for(auto i: cr.civ){
        v1[i.sn]=max(0,c-f1.sum(i.fs.sn-1));
        f1.add(i.fs.sn,1);
        c++;
    }

    sort(cr.civ.begin(),cr.civ.end(),
        [&](pair<pair<int,int>,int> &x,
            pair<pair<int,int>,int> &y
        ){
        if(x.fs.fs==y.fs.fs)return x.fs.sn<y.fs.sn;
        return x.fs.fs>y.fs.fs;
    });

    for(auto i: cr.civ){
        v2[i.sn]=max(0,f2.sum(i.fs.sn));
        f2.add(i.fs.sn,1);
    }

    printv(v2);
    printv(v1);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    solve();    
    return 0;
}