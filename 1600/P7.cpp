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

const ll mod = 1e9+7; //998244353;
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
const int N = 2026;
ll pref[N][N];

void comp(){

    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            pref[i][j] = 0ll;
        }
    }

    ll st = 1;
    for(ll i=1;i<N;i++){
        for(ll j=1;j<=i;j++){
            pref[i][j] = 1ll*(st + j -1)*(st + j - 1);
        }
        st = st + i;
    }

    for(ll i=1;i<N-1;i++){
        for(ll j=1;j<=i;j++){
            pref[i][j] += 0ll + pref[i][j-1];
        }
    }
}

void solve(){
    ll n; cin>>n;

    ll lo = 0,hi = 2500,mid;
    while(hi > lo + 1){
        mid = lo + (hi - lo)/2;

        if( 1ll*(mid*(mid+1))/2 < n){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    // cout<<lo<<'\n';

    ll ind = n - 1ll*(lo*(lo+1))/2;

    // cout<<ind<<" "<<lo<<'\n';

    ll l,r;
    if(ind == 1){
        ll sum = n*n;
        for(int i=lo;i>=1;i--){
            sum += 0ll + pref[i][1];
        }

        cout<<sum<<'\n';
    }
    else if(ind == lo+1){
        ll sum = n*n;
        for(int i=lo;i>=1;i--){
            sum += 0ll +  pref[i][i] - pref[i][i-1];
        }

        cout<<sum<<'\n';
    }
    else{
        ll l = max(ind-1,0ll),r = min(ind,lo);   
        
        ll sum = 1ll*n*n;
        for(ll i=lo;i>=1;i--){
            // cout<<l<<" "<<r<<'\n';
            sum += 0ll + pref[i][r] - pref[i][max(l-1,0ll)];

            l = max(l - 1,0ll), r = min(r,i-1);
        }

        cout<<sum<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    comp();

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