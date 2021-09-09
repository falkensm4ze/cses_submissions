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

void solve(){
    //seive style solution

    int n,tmp;cin>>n;
    const int sz=1e6+7;

    vector<int> v(sz,0);
    vector<bool> vs(sz,0);
    for(int i=0;i<n;i++){
        cin>>tmp;
        vs[tmp]=1;
    }

    for(int i=2;i<sz;i++){
        for(int j=i;j<sz;j+=i){
            if(vs[j])v[i]++;
        }
    }

    tmp=1;
    for(int i=2;i<sz;i++){
        if(v[i]>1)tmp=i;
    }

    cout<<tmp<<"\n";
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