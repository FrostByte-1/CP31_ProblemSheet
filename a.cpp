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
    int n; n = 3;

    vector<int> v(8);
    for(int i=0;i<8;i++){
        v[i] = i;
    }

    do{
        int sum = 0,c = v[0];
        for(int i=0;i<(1 << n);i++){
            c &= v[i];
            sum += __builtin_popcount(c);
        }

        if(sum == 7){
            cout<<sum<<'\n';
            for(auto x : v) cout<<x<<' '; cout<<'\n';
            break;
        }
    }while(next_permutation(v.begin(),v.end()));
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