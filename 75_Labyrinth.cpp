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
 
void solve_testcase(){
    int n,m;cin>>n>>m;
    string s[n];
    pair<int,int> a,b;
    vector<vector<pair<int,int> > > d(n,vector<pair<int,int> >(m,mp(-1,-1)));
    for(int i=0;i<n;i++){
        cin>>s[i];assert(s[i].size()==m);
        for(int j=0;j<m;j++){
            if(s[i][j]=='A')a=mp(i,j);
            else if(s[i][j]=='B')b=mp(i,j);  
            else if(s[i][j]=='#')d[i][j]=mp(-2,-2);        
        }
    }

    int dd[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
    
    function <void(int,int)> gbfs = [&](int sx, int sy){
        
        queue<pair<int, int>> q;
        q.push({sx, sy});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dd){
                int tx = x + dx;
                int ty = y + dy;
                if(tx >= 0 && ty >= 0 && tx < n && ty < m && d[tx][ty] == mp(-1,-1)){
                    d[tx][ty] = mp(x,y);
                    q.push({tx, ty});
                }
            }
        }
    };

    gbfs(a.fs,a.sn);

    if(d[b.fs][b.sn]==mp(-1,-1)){cout<<"NO\n";return;}

    cout<<"YES\n";
    
    string path;
    while(b!=a){
        int r=b.fs,c=b.sn;
        if(d[r][c]==mp(r-1,c))path.push_back('D');
        else if(d[r][c]==mp(r+1,c))path.push_back('U');
        else if(d[r][c]==mp(r,c-1))path.push_back('R');
        else if(d[r][c]==mp(r,c+1))path.push_back('L');
        b=d[r][c];
    }
    cout<<path.size()<<"\n";
    reverse(path.begin(),path.end());
    cout<<path<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve_testcase();
    
    return 0;
}