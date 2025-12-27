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

    vector<array<int,2> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }

    if(n <= 2){
        cout<<"YES\n";
        return;
    }

    sort(v.begin(),v.end(),[&](auto a,auto b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    vector<int> done(n);
    int c1 = 1;
    done[0] = 1;
    int l = v[0][0],r = v[0][1];

    for(int i=1;i<n;i++){
        if(v[i][0] > r){
            done[i] = 1;
            l = v[i][0];
            r = v[i][1];
            c1++;
        }
    }  

    if(c1 == n){
        cout<<"YES\n";
        return;
    }

    int c2 = 1;
    int ind = -1;
    for(int i=0;i<n;i++){
        if(done[i] == 0){
            l = v[i][0];
            r = v[i][1];
            ind = i;
            break;
        }
    }

    for(int i=ind+1;i<n;i++){
        if(done[i] == 0){
            if(v[i][0] > r){
                l = v[i][0];
                r = v[i][1];
                c2++;
            }else{
                cout<<"NO\n";
                return;
            }
        }
    }

    if(c1 + c2 == n){
        cout<<"YES\n";
        return;
    }
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