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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> v(n);
        for(auto &x : v) cin>>x;

        for(ll i=1;i<60;i++){
            set<ll> sett;
            for(int j=0;j<n;j++){
                sett.insert(v[j]%(1LL << i));
            }
            if(sett.size() == 2){
                cout<<(1LL << i)<<"\n";
                break;
            }
        }
    }   
    
    return 0;
}