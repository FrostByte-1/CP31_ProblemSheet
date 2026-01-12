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
        ll n,x,y; cin>>n>>x>>y;
        ll lcm = (x*y)/__gcd(x,y);

        ll cx = n/x,cy = n/y,cxy = n/lcm;

        //cout<<cx<<" "<<cy<<" "<<cxy<<"\n";
        cx -= cxy;
        cy -= cxy;

        cout<<(n*(n+1))/2 - ((n-cx)*(n-cx+1))/2 - cy*(cy+1)/2<<endl;
    }   
    
    return 0;
}