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
vector<int> factor[N];

void solve(){
    int n,m; cin>>n>>m;

    vector<int> v(n);
    for(int &x : v) cin>>x;
    sort(v.begin(),v.end());

    vector<int> cnt(m+1);

    int cc = 0,ans = INT_MAX;    
    int l = 0,r = 0;

    for(;l<n;l++){
        
        while(r < n && cc < m){
            for(auto x : factor[v[r]]){
                if(x <= m){
                    cnt[x]++;
                    if(cnt[x] == 1){
                        cc++;
                    }
                }
            }
            r++;
        }

        if(cc == m){
            ans = min(ans,v[r-1]-v[l]);
        }

        for(auto x : factor[v[l]]){
            if(x <= m){
                cnt[x]--;
                if(cnt[x] == 0){
                    cc--;
                }
            }
        }
    }

    cout<<(ans == INT_MAX ? -1 : ans)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            factor[j].push_back(i);
        }
    }
    
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