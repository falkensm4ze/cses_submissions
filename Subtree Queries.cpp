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

template <typename T> struct segtree {     
    int nseg;
    vector<T> t;
    segtree(int n){
        nseg=n;
        t=vector<T>(nseg<<1,0);  
    }
    void build(){
        for(int i=nseg-1;i>0;--i){
            t[i]=t[i<<1]+t[i<<1|1];
        }
    }
    void modify(int p,T value){
        for(t[p+=nseg]=value;p>1;p>>=1){
            t[p>>1]=t[p]+t[p^1];
        }
    }
    T query(int l,int r){
        T res=0;
        for(l+=nseg,r+=nseg;l<r;l>>=1,r>>=1){
            if(l&1)res+=t[l++];
            if(r&1)res+=t[--r];
        }
        return res;
    }
};

void solve(){
    int n,q;cin>>n>>q;
    vec(ll) val(n,0);
    scanv(val);
    vector<vector<int> > v(n);int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
    }

    vector<pair<int,int> > mark(n,mp(-1,0));int c=-1;  
    function <void(int)> flatr = [&](int r){
        mark[r].fs=++c;
        for(auto i: v[r]){
            if(mark[i].fs<0){
                flatr(i);
            }
        }
        mark[r].sn=c;
        return;
    };

    flatr(0);
    segtree<ll> st(n);
    for(int i=0;i<n;i++){
        st.t[n+mark[i].fs]=val[i];
    }
    st.build();
    int ty,nd;ll xval;
    while(q--){
        cin>>ty;
        if(ty==1){
            cin>>nd>>xval;nd--;
            st.modify(mark[nd].fs,xval);
        }
        else {
            cin>>nd;nd--;
            cout<<st.query(mark[nd].fs,mark[nd].sn+1)<<"\n";
        }
    }
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