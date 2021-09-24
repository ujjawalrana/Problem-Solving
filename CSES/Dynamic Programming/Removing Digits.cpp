// https://cses.fi/problemset/task/1637

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll                      long long int
#define lu                      unsignedlong long int
#define ld                      long double
#define pb                      push_back
#define pf                      push_front
#define in                      insert
#define br                      cout<<"\n"
#define size(x)                 x.size()
#define all(x)                  x.begin(), x.end() 
#define mem(x,s)                memset(x,s,sizeof(x))
#define ps(y,x)                 fixed<<setprecision(y)<<x;
#define lower(x,a)              lower_bound(x.begin(),x.end(),a)-x.begin()
#define upper(x,a)              upper_bound(x.begin(),x.end(),a)-x.begin()
#define find(x,a)               find(x.begin(),x.end(),a)-x.begin()
#define fast                    ios_base::sync_with_stdio(false);cin.tie(NULL)
#define umap                    unordered_map
#define zerobits(x)             __builtin_ctzll(x)
#define setbits(x)              __builtin_popcountll(x)
#define ff                      first
#define ss                      second
#define google(i)               cout<<"Case #"<<i<<": ";
#define print5(a,b,c,d,e)       cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e
#define print4(a,b,c,d)         cout<<a<<" "<<b<<" "<<c<<" "<<d
 
 
template<typename T>
using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
typedef priority_queue<ll,vector<ll>,greater<ll> > min_pq;
typedef priority_queue<ll> max_pq;
 
ll mod_add(ll a,ll b,ll m){a=a%m;b=b%m;return (((a+b)%m)+m)%m;}
ll mod_sub(ll a,ll b,ll m){a=a%m;b=b%m;return (((a-b)%m)+m)%m;}
ll mod_mul(ll a,ll b,ll m){a=a%m;b=b%m;return (((a*b)%m)+m)%m;}
 
const long long int mod=1000000007;
const long long int inf=1000000000000000000;
const long double pie=3.14159265358979323846264338;
 
 
void solve(){   
    ll n;
    cin>>n;
 
    ll c=0;
 
    while(n!=0){
        ll d=n;
        ll r=0;
        while(d!=0){
            ll t=d%10;
            r=max(t,r);
            d/=10;
        }
        n-=r;
        c++;
    }
    cout<<c;
}
 
int main(){
    fast;
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        init();
    #endif
    ll q=1;
    // cin>>q;
    while(q--){
        solve();br;
    }    
}
