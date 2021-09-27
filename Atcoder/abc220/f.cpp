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

vector<vector<ll>>a(2e5+10);
vector<ll>siz(2e5+10,0);
vector<bool>vis(2e5+10,false);
vector<ll>ans(2e5+10,0);

ll level=0,n;

ll dfs(ll pos,ll lvl){

    vis[pos]=1;
    ll c=1;
    for(auto i:a[pos]){
        if(!vis[i]){
            c+=dfs(i,lvl+1);
        }
    }
    
    level+=lvl;
    siz[pos]=c;
    return c;
}

void help(ll pos,ll par){
    if(par!=pos){
        ans[pos]=ans[par]+(n-siz[pos])-siz[pos];
    }
    
    vis[pos]=1;
    
    for(auto i:a[pos]){
        if(!vis[i])help(i,pos);
    }
}
void solve(){   
    
    cin>>n;

    for(ll i=1;i<n;i++){
        ll x,y; cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }

    dfs(1,0);
    ans[1]=level;

    for(ll i=0;i<=n;i++)vis[i]=0;
    
    help(1,1);
    for(ll i=1;i<=n;i++)cout<<ans[i]<<" ";
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
