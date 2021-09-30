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

vector<ll>height(2e5+10);
vector<ll>smell(2e5+10);
vector<ll>dp(2e5+10);
vector<ll>seg(8e5+100);

ll sum(ll index,ll qstart,ll qend,ll start,ll end){
    if(start>end)return 0;
    if(end<qstart or start>qend)return 0;

    if(qstart<=start and end<=qend){
        return seg[index];
    }
    ll mid=(start+end)/2;

    return max(sum(2*index,qstart,qend,start,mid),sum(2*index+1,qstart,qend,mid+1,end));
}

void fit(ll index,ll start,ll end,ll value){
    if(start>end)return ;
    if(start==end){
        seg[index]=dp[value]; return;
    }

    ll mid=(start+end)/2;
    if(value<=mid)fit(2*index,start,mid,value);
    else fit(2*index+1,mid+1,end,value);

    seg[index]=max(seg[2*index],seg[2*index+1]);
}

void solve(){   
    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){
        cin>>height[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>smell[i];
    }

    ll ans=0;

    for(ll i=1;i<=n;i++){
        dp[height[i]]=sum(1,1,height[i],1,n)+smell[i];
        fit(1,1,n,height[i]);
        ans=max(ans,dp[height[i]]);
    }

    for(ll i=1;i<=n;i++)ans=max(ans,dp[i]);
    cout<<ans;

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
