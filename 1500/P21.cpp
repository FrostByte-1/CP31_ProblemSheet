// Written by Nirupam (cf: Nirupam)
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

#define ll long long 
#define all(x) (x).begin(),(x).end()

const ll mod = 1e9+7;
ll pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return result;
}

// Problem Statement
/*

*/

// Observation
/*

*/

// Algorithm
/*

*/
const int N = 1e5 + 5;
vector<int> g[N];
vector<bool> vis(N);

int dfs(int s){

    vis[s] = true;
    int c = 1;

    for(auto child : g[s]){
        if(vis[child]) continue;
        c += dfs(child);
    }

    return c;
}

void solve(){
    int n,k; cin>>n>>k;

    for(int i=0;i<n-1;i++){
        int u,v,wt; cin>>u>>v>>wt;

        if(wt == 0){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    ll ans = pow(n,k,mod);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int sz = dfs(i);
            ans = (ans%mod - pow(sz,k,mod) + mod)%mod;
        }
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    solve();

    return 0;
}

// Golden Rules
/*
    Solutions are simple.

    Proofs are simple.

    Implementations are simple.
*/