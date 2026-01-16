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
    We want to make some update in the array and then check if it satisfies any segment 

    at that point 

    fenwick tree ?? 
    binary search ?? 

    bs on ans and then make ones array and check for all segment using BIT
    there are mid no. of ones in the array of length n
*/

// Algorithm
/*
    fenwick tree works the same but with 0 based indexing and we want to add +1 in range 
    when using segment tree
*/

bool good(vector<array<int,2> > &seg, vector<int> &v,int n,int m,int mid){

    BIT<ll> fentree(n+1);
    for(int i=0;i<mid;i++){
        fentree.set(v[i],1);
    }

    for(int i=0;i<m;i++){
        int l = seg[i][0], r = seg[i][1];

        int pr = fentree.rq(r);
        int pl = fentree.rq(l-1);

        if( (pr - pl) > (r - l + 1)/2 ){
            return true;
        }
    }

    return false;
}

void solve(){
    int n,m; cin>>n>>m;

    vector<array<int,2> > seg(m);
    for(int i=0;i<m;i++) cin>>seg[i][0]>>seg[i][1];

    int q; cin>>q;
    vector<int> v(q);
    for(int &x : v) cin>>x;

    int lo = 0,hi = q+1,mid;
    while(hi > lo + 1){
        mid = lo + (hi - lo)/2;

        if(good(seg,v,n,m,mid)){
            hi = mid;
        }else{
            lo = mid;
        }
    }

    cout<<(lo == q ? -1 : hi)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
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