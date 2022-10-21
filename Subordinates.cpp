#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define dbg(...)
#else
#include "lib/debug.h"
#endif
using ll = long long;
const int MAX_N = 1e5;
template <class T>
using vec = vector<T>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
vector<vector<ll>>tree;
ll c;
vector<ll>sizes;

void dfs(ll x) {
    sizes[x] = 1;
    for (const auto & i : tree[x]) {
        dfs(i);
        sizes[x] += sizes[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    sizes.resize(n);
    tree.resize(n);
    FOR(i, 1, n) {
        ll b;
        cin >> b;
        tree[--b].push_back(i);
    }
    dfs(0);
    FOR (i, 0, n) {
        cout << sizes[i]-1 << " ";
    }
}