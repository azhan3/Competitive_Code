#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define dbg(...)
#else
#include "lib/debug.h"
#endif

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vec = vector<T>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vector<ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
template <class T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class R>
using indexed_map =
    tree<K, R, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (const auto & a : c)
#define all(x) x.begin(), x.end()

#define MOD 1000000007
//#define MOD 998244353

ll n, m;

struct graph {
    ll n;
    vector <vector <ll>>g;
    vector<bool>visited;
    graph (ll n) {
        this->n = n;
        g.resize(n);
        visited.resize(n, false);
    }
    void add(ll v, ll w) {
        g[v].push_back(w);
        g[w].push_back(v);
    }
    void solvee() {
        vll show;
        ll count = 0;
        dfs(0);
        FOR(i, 0, n) {
            if (!visited[i]) {
                count ++;
                dfs(i);
                add(i, 0);
                show.push_back(i);
            }
        }
        cout << count << "\n";
        TRAV(i, show) cout << 1 << " " << i+1 << "\n";
    }
    void dfs(ll v) {
        visited[v] = true;
        dbg(v);
        for (const auto & i : g[v]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    graph cities(n);
    while (m--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        cities.add(a,b);
    }

    cities.solvee();
}


