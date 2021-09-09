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
    int n,q;cin>>n>>q;
    vector<vector<int> > v(n);int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x-1].pb(y-1);
        v[y-1].pb(x-1);
    }

    vector<vector<int> > anc(n,vector<int>(24,-1)); 
    function <void(int)> pr = [&](int r){
        for(auto i: v[r]){
            if(anc[i][0]<0){
                anc[i][0]=r;
                pr(i);
            }
        }
        return;
    };
    anc[0][0]=0;pr(0);anc[0][0]=-1;
            
    for(int i=1;i<24;i++){
        for(int j=0;j<n;j++){
            if(anc[j][i-1]<0)continue;
            anc[j][i]=anc[anc[j][i-1]][i-1];
        }
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
    
    function<bool(int&,int&)> isanc = [&](int& a,int& b){
        if(mark[a].sn>=mark[b].fs && mark[a].fs<=mark[b].fs)return 1;
        else return 0;
    };
    
    function<int(int,int)> kanc = [&](int a,int k){
        int i=0;
        while(k){
            if(k&1){a=anc[a][i];}
            k>>=1;i++;
        }
        return a;
    };
    
    function<int(int,int)> lca = [&](int a,int b){
        if(isanc(a,b))return a;
        else if(isanc(b,a))return b;
        int i=24;
        while(i>0){
            if(anc[a][i]>=0){
                if(!isanc(anc[a][i],b))a=anc[a][i];
            }
            i--;
        }
        return anc[a][i];
    };

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<i<<" "<<j<<" "<<lca(i,j)<<"\n";
    //     }
    // }

    vector<int> val(n,0);
    vector<int> res(n,0);
    
    while(q--){
        int a,b;cin>>a>>b;a--,b--;
        int l=lca(a,b);
        val[a]+=1;val[b]+=1;val[l]-=1;
        if(anc[l][0]>=0)val[anc[l][0]]=-1;
    }

    vector<bool> vs(n,0);
    function <int(int)> dfs = [&](int r){
        vs[r]=1;
        res[r]+=val[r];
        for(auto i: v[r]){
            if(!vs[i]){
                res[r]+=dfs(i);
            }
        }
        return res[r];
    };
    int dumper = dfs(0);
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


/*

          0
       1     2
           3   4    

*/