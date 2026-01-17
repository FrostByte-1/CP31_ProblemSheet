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
    DSU ?? 

    if we can get an open vertex with only 1 edge or dsu of size 2 then we can merge this in others
    
*/

// Algorithm
/*

*/
const int N = 2e5 + 5;
vector<bool> vis(N);
vector<int> g[N],deg(N);

int mxsz = 0;

bool dfs(int s){

    vis[s] = true;
    bool can = (deg[s] == 1);
    mxsz++;

    for(auto child : g[s]){
        if(vis[child]) continue;

        can |= dfs(child);
    }

    return can;
}

void solve(){
    int n; cin>>n;

    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        g[i].clear();
        deg[i] = 0;
        vis[i] = false;
    }

    for(int i=1;i<=n;i++){
        g[i].push_back(v[i]);
        g[v[i]].push_back(i);

        deg[i]++;
        deg[v[i]]++;
    }

    int c2 = 0,total = 0;
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){

            total++;
            mxsz = 0;
            bool has = dfs(i);

            if(has || mxsz == 2){
                c2++;
            }
        }
    }

    if(c2 == 0 || c2 == 1){
        cout<<total<<" "<<total<<'\n';
    }else{
        cout<<total - c2 + 1<<" "<<total<<'\n';
    }
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