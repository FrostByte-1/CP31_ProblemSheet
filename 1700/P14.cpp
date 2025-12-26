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

void solve(){
    int n; cin>>n;
    vector<ll> v(n+2);
    for(int i=1;i<=n;i++) cin>>v[i];

    vector<ll> pref(n+2),suf(n+2);

    for(int i=1;i<=n;i++){
        pref[i] = max(pref[i-1],v[i]+i);
    }

    suf[n] = v[n]-n;
    for(int i=n-1;i>=1;i--){
        suf[i] = max(suf[i+1],v[i]-i);
    }

    ll ans = 0;
    for(int i=2;i<=n-1;i++){
        ans = max(ans,v[i] + pref[i-1] + suf[i+1]);
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

// Golden Rules
/*
    Solutions are simple.

    Proofs are simple.

    Implementations are simple.
*/