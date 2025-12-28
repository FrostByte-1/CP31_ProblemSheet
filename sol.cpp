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
    int n,m; cin>>n>>m;

    vector<array<int,2> > v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i][0];
        v[i][1] = i;
    }

    sort(v.begin(),v.end(),[&](auto a,auto b){
        return a[0] < b[0];
    });

    if(m > n/2){
        cout<<-1<<'\n';
        return;
    }
    else if(m == 0){
        int ind = -1;
        ll sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += v[i][0];
            if(sum >= v[n][0]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            cout<<-1<<'\n';
            return;
        }
        int c = ind - 1 + (n-1)-(ind)+1;

        cout<<c<<'\n';
        for(int i = 1;i<ind;i++){
            cout<<v[i][1]<<" "<<v[i+1][1]<<'\n';
        }

        for(int i = ind;i <= n-2;i++){
            cout<<v[i][1]<<" "<<v[n][1]<<'\n';
        }

        cout<<v[n][1]<<" "<<v[n-1][1]<<'\n';
    }else{
        cout<<n-m<<'\n';

        for(int i=1;i<=m-1;i++){
            cout<<v[n-i+1][1]<<" "<<v[i][1]<<'\n';
        }

        for(int i=m;i<=n-m-1;i++){
            cout<<v[i][1]<<" "<<v[i+1][1]<<'\n';
        }

        cout<<v[n-m+1][1]<<" "<<v[n-m][1]<<'\n';
    }
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