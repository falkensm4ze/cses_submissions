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
stack<string> st;
string s1;

void func(string tmp,int p){
    tmp[p]='0'+1-(tmp[p]-'0');
    if(s.find(tmp)==s.end()){
        s.insert(tmp);
        st.push(tmp);
    }
    else return;
    for(int i=0;i<tmp.size();i++){
        func(tmp,i);
    }
    return;
}  

void solve(){
    int n;cin>>n;
    s1=string(n,'0');
    s.insert(s1);
    st.push(s1);
    for(int i=0;i<n;i++)func(s1,i);

    while(!st.empty()){cout<<st.top()<<"\n";st.pop();}
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    //precomp();
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    return 0;
}