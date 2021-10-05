/* survival_001 */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define ll                      long long int
#define lu                      unsigned long long int
#define ld                      long double
#define pb                      push_back
#define ppb                     pop_back
#define pf                      push_front
#define in                      insert
#define br                      cout<<"\n";
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


template<typename T>
using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef priority_queue<ll,vector<ll>,greater<ll> > min_pq;
typedef priority_queue<ll> max_pq;

ll add(ll a,ll b,ll m){a=a%m;b=b%m;return (((a+b)%m)+m)%m;}
ll sub(ll a,ll b,ll m){a=a%m;b=b%m;return (((a-b)%m)+m)%m;}
ll mul(ll a,ll b,ll m){a=a%m;b=b%m;return (((a*b)%m)+m)%m;}

const long long int mod=1000000007;
const long long int inf=1000000000000000000;
const long double pie=3.14159265358979323846264338;

vector<vector<ll>>a(2e5+1),dp(2e5+10,vector<ll>(3,-1));
vector<ll>vis(2e5+1,0);

ll dfs(ll pos,ll ok){

    if(dp[pos][ok]!=-1)return dp[pos][ok];
    
    ll ans=1;
    vis[pos]=1;

    for(auto i:a[pos]){
        if(vis[i]==0){
            if(ok)ans=mul(ans,dfs(i,1-ok),mod);
            else ans=mul(ans,add(dfs(i,ok),dfs(i,1-ok),mod),mod);
        }
    }

    vis[pos]=0;
    return dp[pos][ok]=ans;
}
void solve(){   
    ll n;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        ll x,y; cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    ll ans=dfs(1,1);
    
    for(ll i=0;i<=n;i++)dp[i][0]=dp[i][1]=-1;

    cout<<add(ans,dfs(1,0),mod);
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
        get_fact(mod);
    #endif
    ll q=1;
    // cin>>q;
    while(q--){
        solve();br;
    }   
    return 0; 
}
