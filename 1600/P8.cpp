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

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(int &x : v) cin>>x;

    sort(v.begin(),v.end());

    int mval = v[n-1] - v[0];

    vector<int> ans;

    int l,r = n-2;
    ll sum = v[n-1];
    ans.push_back(v[n-1]);

    for(l = 0; l < r; ){

        if(sum > 0){
            ll sum2 = 0;

            while(l < r && sum > 0){
                sum += v[l];
                sum2 += v[l];
                ans.push_back(v[l]);
                l++;
            }

            if(abs(sum2) >= mval){
                cout<<"No\n";
                return;
            }

        }else if(sum < 0){
            ll sum2 = 0;

            while(l < r && sum < 0){
                sum += v[r];
                sum2 += v[r];
                ans.push_back(v[r]);
                r--;
            }

            if(abs(sum2) >= mval){
                cout<<"No\n";
                return;
            }
            
        }else{
            sum = v[r];
            ans.push_back(v[r]);
            r--;
        }
    
    }
    
    sum = 0;
    for(int i=l;i<=r;i++){
        sum += v[i];
        ans.push_back(v[i]);
    }

    if(abs(sum) >= mval){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
    for(auto x : ans) cout<<x<<" "; cout<<'\n';
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