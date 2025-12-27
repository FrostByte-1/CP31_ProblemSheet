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
const int N = 2e5 + 5;
vector<int> d[N];

void seive(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            d[j].push_back(i);
        }
    }
}

void solve(){
    int n; cin>>n;

    vector<int> v(n);
    for(int &x : v) cin>>x;

    int ans = 0;
    for(auto k : d[n]){

        if(k == n){
            ans++;
            continue;
        }

        vector<vector<int> > arr(k);

        for(int i=0;i<n;i++){
            arr[i%k].push_back(v[i]);
        }

        for(int i=0;i<k;i++){
            for(int j=0;j<(n/k)-1;j++){
                arr[i][j] = abs(arr[i][j] - arr[i][j+1]);
            }
        }

        vector<int> g(k);

        for(int i=0;i<k;i++){
            g[i] = arr[i][0];
        }

        for(int i=0;i<k;i++){
            for(int j=1;j<(n/k)-1;j++){
                g[i] = __gcd(g[i],arr[i][j]);
            }
        }

        bool can = true;
        int g2 = g[0];
        for(int i=0;i<k;i++){
            if(g[i] == 1){
                can = false;
            }else{
                g2 = __gcd(g2,g[i]);
            }
        }

        if(can && g2 != 1) ans++;
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    seive();

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