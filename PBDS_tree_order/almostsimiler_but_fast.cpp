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

ll ara[MX],tree[4*MX];
ll les[MX],great[MX];
vector <ll>temp;
map<ll,ll> onto;
void update(ll node,ll l,ll r,ll pos,ll u){
     if(l==r){
        tree[node]=u;
        return ;
     }
     ll mid=(l+r)/2;
     if(pos<=mid)
        update(2*node,l,mid,pos,u);
     else
        update(2*node+1,mid+1,r,pos,u);
     tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(ll node,ll l,ll r,ll ql,ll qr){
    if(ql>r || qr<l)
        return 0;
    if(ql<=l && qr>=r)
        return tree[node];
    ll mid=(l+r)/2;
    return query(2*node,l,mid,ql,qr)+query(2*node+1,mid+1,r,ql,qr);
}

void solve(int caseno){
    ll i,j,k;
    ll n,res=0;
    cin>>n;
    temp.clear();
    onto.clear();
    for(int i=0; i<n+1; i++) {
        great[i]=0;
        les[i]=0;
    }
    for(int i=0; i<4*n+1; i++) {
        tree[i] = 0;
    }
    for(i=0;i<n;i++){
        cin>>ara[i];
        temp.push_back(ara[i]);
    }
    sort(temp.begin(),temp.end());
    for(i=0;i<n;i++)
        onto[temp[i]]=i;
    for(i=0;i<n;i++)
        ara[i]=onto[ara[i]];
    for(i=0;i<n;i++){
        if(ara[i]==0)
            great[i]=i;
        else
            great[i]=query(1,0,n,ara[i]+1,n);
        update(1,0,n,ara[i],1);
    }
    for(int i=0; i<4*n+1; i++) {
        tree[i] = 0;
    }
    for(i=n-1;i>=0;i--){
        if(ara[i]==0)
            les[i]=0;
        else
            les[i]=query(1,0,n,0,ara[i]-1);
        update(1,0,n,ara[i],1);
    }
    for(i=0;i<n;i++)
        res+=(les[i]);
    cout<<res<<'\n';
    return;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases,caseno=0;
    cin>>cases;
    while(cases--){
        solve(++caseno);
    }
    return 0;
}           