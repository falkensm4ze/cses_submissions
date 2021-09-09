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
#define priority_queue priq

typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}

struct winbuck {
    multiset<int> lo;
    multiset<int> hi;

    void bal(){
        while(lo.size()<hi.size()){
            lo.insert(*hi.begin());
            hi.erase(hi.find(*hi.begin()));
        }
        while(lo.size()-1>hi.size()){
            hi.insert(*lo.rbegin());
            lo.erase(lo.find(*lo.rbegin()));
        }
    }

    void ins(int x){
        bal();
        if(x>*lo.rbegin()){
            hi.insert(x);
        }
        else lo.insert(x);
        bal();
    }

    void del(int x){
        if(hi.find(x)!=hi.end())hi.erase(x);
        else if(lo.find(x)!=lo.end()){
            lo.erase(lo.find(x));
        }
        bal();
    }

    int getm(){
        bal();
        return *(lo.rbegin());
    }
};

void solve(){
    int n,k;cin>>n>>k;
    
    vector<int> a(n);
    scanv(a);
    winbuck w;
    
    vector<int> tmp(a.begin(),a.begin()+k);
    sort(tmp.begin(),tmp.end());
    //printv(tmp);
    for(int i=0,j=tmp.size()-1;i<=j;i++,j--){
        w.lo.insert(tmp[i]);
        if(i<j){
            w.hi.insert(tmp[j]);
        }
    }
    w.bal();

    vector<int> res;
    res.pb(w.getm());
    for(int i=k;i<n;i++){
        w.ins(a[i]);
        w.del(a[i-k]);
        res.pb(w.getm());
    }

    printv(res);
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