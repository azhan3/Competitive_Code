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

ll dirx[] = {0, 0, 1, 1, 1, -1, -1, -1};
ll diry[] = {1, -1, 1, 0, -1, 1, 0, -1};
ll d, n;
vector<vector<ll>>killed(1025, vector<ll>(1025));

bool valid(ll r, ll c) {
    if (r < 0 || r >= 1025 || c < 0 || c > 1025) return false;
    return true;
}

void search(ll r, ll c, ll v, ll depth, ll ind) {
    if (depth == d+1) return;
    killed[r][c] += v;
    ll newx = c + dirx[ind], newy = r + diry[ind];
    if (valid(newx, newy)) {
        search(newy, newx, v, depth+1, ind);
    }
}

void solve() {
    cin >> d >> n;

    while (n--) {
        ll x, y, v;
        cin >> x >> y >> v;
        x--; y--;
        FOR (i, 0, 8) {
            search(y, x, v, 0, i);
        }
        killed[y][x] -= v * 7;
    }
    tuple<ll, ll, ll> max_rat;
    max_rat = make_tuple(1, 1, killed[0][0]);
    FOR (i, 0, 1025) {
        FOR (j, 0, 1025) {
            if (killed[i][j] > get<2>(max_rat)) {
                get<0>(max_rat) = j+1;
                get<1>(max_rat) = i+1;
                get<2>(max_rat) = killed[i][j];
            }
        }
    }
    cout << get<0>(max_rat) << " " << get<1>(max_rat) << " " << get<2>(max_rat) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
}