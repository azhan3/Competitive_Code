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

void setIO(string s) {
   freopen((s + ".in").c_str(), "r", stdin);
   freopen((s + ".out").c_str(), "w", stdout);
}

#define MOD 1000000007
//#define MOD 998244353

#define FASTIO
#define PRECISION
//#define FILE "file"

#define SINGLE
//#define MULTIPLE
//#define GOOGLE

struct graph {
    ll n, farthest, length, mm=0;
    vector <vector<ll>> g;
    vector <bool> visited;
    graph(ll n) {
        this->n = n;
        g.resize(n);
        visited.resize(n, false);
    }
    void add(ll v, ll w) {
        g[v].push_back(w);
    }

    void solvee() {
        FOR(i, 0, n) {
            farthest=0;
            length=0;
            fill(all(visited), false);
            dfs(i);
            dbg(farthest);
            mm = max(mm, farthest);
        }
        cout << mm << "\n";
    }

    void dfs(ll v) {
        visited[v] = true;
        TRAV(i, g[v]) {
            if (!visited[i]) {
                length++;
                dfs(i);
                length--;
            }
        }
        farthest = max(farthest, length);
    }

};

void solve() {
    setIO("moocast");
    ll n, x, y, p, dist;
    cin >> n;
    graph cows(n);
    vector<vector<ll>> cow_coords(n, vector<ll>(3));
    FOR(i, 0, n) {
        cin >> cow_coords[i][0] >> cow_coords[i][1] >> cow_coords[i][2];
    }
    FOR(i, 0, n) {
        FOR(j, i+1, n) {
            dist = sqrt(pow(cow_coords[i][0] - cow_coords[j][0], 2) + pow(cow_coords[i][1] - cow_coords[j][1], 2));
            if (dist <= cow_coords[i][2]) cows.add(i, j);
            if (dist <= cow_coords[j][2]) cows.add(j, i);
        }
    }
    cows.solvee();
    dbg(cows.g);
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen((FILE + string(".in")).c_str(), "r", stdin);
    freopen((FILE + string(".out")).c_str(), "w", stdout);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
#endif
#ifdef GOOGLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}