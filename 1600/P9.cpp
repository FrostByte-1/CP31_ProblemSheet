// Written by Nirupam (cf: Nirupam)
#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> class SegmentTree {
private:
    const T DEFAULT = 0;

    vector<T> segtree;
    int len;

public:
    SegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
        }
    }

    T rq(int start, int end) {
        T sum = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { sum = sum + segtree[start++]; }
            if (end % 2 == 1) { sum = sum + segtree[--end]; }
        }
        return sum;
    }
};

template <class T> class BIT {
private:

    int size;
    vector<T> bit;
    vector<T> arr;

public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    void set(int ind, T val) { add(ind, val - arr[ind]); }

    void add(int ind, T val) {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
    }

    T rq(int ind) {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
        return total;
    }
};

#define ll long long 
#define all(x) (x).begin(),(x).end()

const ll mod = 998244353;
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
const int N = 3e5 + 5;
vector<int> fact(N),invfact(N);

void comp(){

    fact[0] = 1;
    invfact[0] = 1;

    ll sum = 1;
    for(int i=1;i<N;i++){
        sum = ( (sum%mod) * (i%mod) ) % mod;
        fact[i] = sum;
    }

    sum = 1;
    for(int i=1;i<N;i++){
        sum = ((sum%mod) * (pow(i,mod-2,mod)%mod )) % mod;
        invfact[i] = sum;
    }
}

void solve(){
    int n; cin>>n;

    vector<array<int,3> > v(n/3);
    for(int i=0;i<n/3;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }

    vector<int> mx(n/3);
    for(int i=0;i<n/3;i++){
        mx[i] = max({v[i][0] + v[i][1],v[i][1] + v[i][2],v[i][2] + v[i][0]});
    }

    vector<int> dp(n/3);

    for(int i=0;i<n/3;i++){
        dp[i] = (v[i][0] + v[i][1] == mx[i]) + (v[i][1] + v[i][2] == mx[i]) + (v[i][2] + v[i][0] == mx[i]);
    }

    ll ans = 1;
    for(int i=0;i<n/3;i++){
        ans = ( (ans%mod) * (dp[i]%mod) ) % mod;
    }

    // cout<<ans<<'\n';

    ans = (ans%mod) * (fact[n/3]%mod) % mod;
    ans = (ans%mod) * (invfact[n/6]%mod) % mod;
    ans = (ans%mod) * (invfact[n/6]%mod) % mod;

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    comp();

    // for(int i=0;i<50;i++){
    //     cout<<fact[i]<<" "<<invfact[i]<<'\n';
    // }
    
    solve();

    return 0;
}

// Golden Rules
/*
    Solutions are simple.

    Proofs are simple.

    Implementations are simple.
*/