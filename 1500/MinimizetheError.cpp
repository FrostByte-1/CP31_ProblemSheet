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
    int n,k1,k2; cin>>n>>k1>>k2;

    multiset<int> sett;

    vector<int> a(n),b(n);
    for(int &x : a) cin>>x;
    for(int &x : b) cin>>x;

    for(int i = 0; i<n; i++){
        sett.insert(abs(a[i]-b[i]));
    }

    for(int i=0;i<k1+k2;i++){
        auto it = --sett.end();

        if(*it >= 0){
            if(*it == 0){
                sett.insert(1);
                sett.erase(it);
            }else{
                sett.insert(*it-1);
                sett.erase(it);
            }
        }
    }

    ll ans = 0;
    for(auto x : sett){
        ans += 1ll*x*x;
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