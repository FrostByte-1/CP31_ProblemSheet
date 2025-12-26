#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        
        vector<int> v(n+1);
        
        for(int i=1;i<=n;i++){
            v[i] = s[i-1] - '0';
            v[i] += v[i-1];
        }
        
        map<int,int> mapp;
        
        for(int i=0;i<=n;i++){
            v[i] -= i;
            mapp[v[i]]++;
            
        }
        long long ans = 0;
        
        for(auto [x,y]: mapp){
            ans += 1ll*(1ll*y*(y-1))/2;
        }
        
        cout<<ans<<'\n';
    }
}