// Created by KHALED MOSHARRAF PARVEZ
#include <bits/stdc++.h>

#define whatis1(x) cout<<#x<<"="<<x<<'\n'
#define whatis2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define whatis3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define whatisArray(arr,n) cout<<#arr<<", Size: "<<n<<'\n';for(int m=0;m<n;m++)  cout<<arr[m]<<" ";cout<<'\n';
#define whatArray2D(arr,m,n) cout<<#arr<<", Size: "<<m<<","<<n<<'\n';for(int mm=0;mm<m;mm++){for(int nn=0;nn<n;nn++)cout<<arr[mm][nn]<<" ";cout<<'\n';} 
#define caseprint(caseno,ans) cout<<"Case "<<caseno<<": "<<ans<<'\n'
#define endl '\n'
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
constexpr int MX = 200005;

void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}

#define int long long

string str;
int n;
int dp[15][3][3];
int func(int pos,int isSmall,int hasStarted){
    if(pos>=n)return 1;
    int & ref = dp[pos][isSmall][hasStarted];
    if(ref!=-1){
        return ref;
    }
    int low = 0,hi = 9;
    if(!isSmall) hi=str[pos]-'0';
    int val = 0;
    for(int i=low; i<=hi; i++) {
        int newSmall = isSmall|(i<hi);
        int suf = 0;
        if(i==0&&hasStarted)
        suf =1;
        
        val += (func(pos+1,newSmall,hasStarted|(i!=0))+suf);
    }
    ref = val;
    return ref;


}

void solve(int caseno){
    int a,b;
    memset(dp,-1,sizeof(dp));
    cin>>a>>b;
    str = to_string(b);
    n = str.size();
    int ans1 =func(0,0,0);
   // whatis1(ans1);
    int ans2 = 0;
   // a++;
    
    memset(dp,-1,sizeof(dp));
    str = to_string(a);
    n = str.size();
    ans2 =func(0,0,0);
 //   whatis2(ans1,ans2);
    int res = ans1-ans2;
    cout<<res<<'\n';
    return;
    
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}