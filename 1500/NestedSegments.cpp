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

bool check(vector<array<int,3> > &v,int i,int j){

    if(v[i][0] <= v[j][0] && v[i][1] >= v[j][1]){
        return true;
    }

    return false;
}

void solve(){
    int n; cin>>n;

    vector<array<int,3> > v(n);
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1],v[i][2] = i;

    sort(v.begin(),v.end(),[&](auto a,auto b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    ordered_set sett;

    int ind = -1;
    for(int i=0;i<n;i++){
        auto k = sett.size() - sett.order_of_key(v[i][1]);

        if(k > 0){
            ind = i;
            break;
        }

        sett.insert(v[i][1]);
    }

    if(ind == -1){
        cout<<"-1 -1\n";
        return;
    }

    for(int i=0;i<n;i++){
        if(i != ind){

            if(check(v,i,ind)){
                cout<<v[ind][2]+1<<" "<<v[i][2]+1<<'\n';
                return;
            }else if(check(v,ind,i)){
                cout<<v[i][2]+1<<" "<<v[ind][2]+1<<'\n';
                return;
            }
            
        }
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