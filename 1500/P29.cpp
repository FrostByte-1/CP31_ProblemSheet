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

    int c1 = 0;
    vector<int> v(n);
    for(int &x : v){
        cin>>x;
        if(x == 1) c1++;
    }

    if(c1 == n){
        cout<<0<<'\n';
        return;
    }

    if(c1){
        cout<<n-c1<<'\n';
        return;
    }

    int mn = INT_MAX;
    for(int i=0;i<n;i++){
        int g = v[i];
        for(int j=1;i+j<n;j++){
            g = __gcd(g,v[i+j]);
            if(g == 1){
                mn = min(mn,j);
            }
        }
    }

    cout<<(mn == INT_MAX ? -1 : mn + n-1)<<'\n';
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