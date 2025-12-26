// Written by Nirupam (cf: Nirupam)
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

#define ll long long 
#define all(x) (x).begin(),(x).end()

const ll mod = 998244353;
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

void solve(){
    int n,m; cin>>n>>m;

    vector<ll> a(n),b(m);

    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll ans = 0;
    for(int i=0;i<n;i++){
        int k = upper_bound(b.begin(),b.end(),(a[i]-1))-b.begin();
        // cout<<k<<" ";
        ans = (ans%mod + (1ll*a[i]%mod*(k))%mod)%mod;

        k = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
        // cout<<k<<'\n';
        ans = (ans%mod - (1ll*a[i]*(m-k))%mod + mod)%mod;
    }

    // cout<<ans<<'\n';
    
    for(int i=0;i<m;i++){
        int k = upper_bound(a.begin(),a.end(),(b[i]-1))-a.begin();
        ans = (ans%mod + (1ll*b[i]*(k))%mod)%mod;

        k = upper_bound(a.begin(),a.end(),b[i]) - a.begin();
        ans = (ans%mod - (1ll*b[i]*(n-k))%mod + mod)%mod;
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