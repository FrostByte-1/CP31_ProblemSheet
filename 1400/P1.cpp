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
        int n,m; cin>>n>>m;

        vector<int> v(n),zeroes;
        for(int &x : v) cin>>x;

        ll digits = 0;
        for(int i=0;i<n;i++){
            string s = to_string(v[i]);
            
            int l = s.size()-1,z = 0;
            while(s[l] == '0'){
                l--;
                z++;
            }

            if(z > 0) zeroes.push_back(z);

            digits += s.size() - z;
        }

        // for(auto x : zeroes) cout<<x<<' '; cout<<'\n';

        sort(zeroes.rbegin(),zeroes.rend());

        for(int i=1;i<zeroes.size();i+=2){
            digits += zeroes[i];
        }

        if(digits > m) cout<<"Sasha\n";
        else cout<<"Anna\n";
    }
    
    return 0;
}   