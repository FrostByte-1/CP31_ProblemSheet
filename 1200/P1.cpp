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
        vector<pair<ll,ll> > a(n),b(n),c(n);
        ll x;
        for(int i=0;i<n;i++){
            cin>>x;
            a[i] = {x,i};
        }

        for(int i=0;i<n;i++){
            cin>>x;
            b[i] = {x,i};
        }

        for(int i=0;i<n;i++){
            cin>>x;
            c[i] = {x,i};
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());

        ll ans = LLONG_MIN;

        for(int i=n-3;i<n;i++){
            for(int j=n-3;j<n;j++){
                for(int k=n-3;k<n;k++){
                    if(a[i].second != b[j].second && b[j].second != c[k].second && c[k].second != a[i].second){
                        ans = max(ans,a[i].first+b[j].first+c[k].first);
                    }
                }
            }
        }

        cout<<ans<<"\n";

    }   
    
    return 0;
}