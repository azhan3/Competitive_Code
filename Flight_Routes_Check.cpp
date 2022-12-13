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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>adj(n);
    while (m--) {
        ll a, b;
        cin >> a >> b; a--;b--;
        adj[a].push_back(b);
    }
    vector<ll>visited;
    ll remaining=n;
    auto dfs = [&](ll x, auto &&dfs)->void {
        visited[x] = true;
        remaining--;
        for (const auto & i : adj[x]) {
            if (!visited[i]) dfs(i, dfs);
        }
    };
    FOR(i, 0, n) {
        visited.assign(n, false);
        remaining = n;
        dfs(i, dfs);
        if (remaining != 0) {
            ll not_visited;
            FOR (j, 0, n) {
                if (!visited[j]) {
                    not_visited = j+1;
                    break;
                }
            }
            cout << "NO\n" << i+1 << " " << not_visited << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}