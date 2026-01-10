// Written by Nirupam (cf: Nirupam)
#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll mod = 1e9+7;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin>>t;
    while(t--){
        int n,x,y; cin>>n>>x>>y;
        vector<int> v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        map<pair<ll,ll>,ll> mapp;

        ll ans = 0;
        for(int i=0;i<n;i++){
            if(v[i]%x == 0){
                ans += mapp[{v[i]%x,v[i]%y}];
            }else{
                ans += mapp[{x-v[i]%x,v[i]%y}];
            }
            mapp[{v[i]%x,v[i]%y}]++;
        }

        cout<<ans<<'\n';
    }   
    
    return 0;
}