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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream fin("fenceplan.in");
    ll n, m, perimeter=INT_MAX;
    fin >> n >> m;
    vector<pair<ll, ll>>cow(n);
    FOR(i, 0, n) {
        ll x, y;
        fin >> x >> y;
        cow[i] = {x, y};
    }
    vector<vector<ll>>adj(n);
    FOR(i, 0, m) {
        ll a, b;
        fin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<ll, ll>>points;
    vector<ll>visited(n, false);
    auto dfs = [&](ll x, auto &&dfs)->void {
        visited[x] = true;
        points.push_back(cow[x]);
        for (auto & i : adj[x]) {
            if (!visited[i]) dfs(i, dfs);
        }
    };
    FOR (i, 0, n) {
        points.clear();
        if (visited[i]) continue;
        dfs(i, dfs);
        ll max_X = 0, max_Y = 0, min_X = INT_MAX, min_Y = INT_MAX;
        for (const auto & i : points) {
            ll x = i.first, y = i.second;       
            max_X = max(max_X, x);
            max_Y = max(max_Y, y);
            min_X = min(min_X, x);
            min_Y = min(min_Y, y);
        }
        perimeter = min(perimeter, (max_X-min_X)*2+(max_Y-min_Y)*2);
    }
    ofstream("fenceplan.out") << perimeter << endl;
}