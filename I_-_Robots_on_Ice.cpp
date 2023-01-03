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

ll m, n, total, order_a, order_b, order_c, counter;
vector<vector<ll>>grid;
vector<vector<ll>>paths;
vector<vector<bool>>visited;

template <class T>
void print_mat(vector<vector<T>>mat) {
    for (auto i : mat) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

struct coord {
    ll r, c;
};

vector<coord>checkpoints(3);

coord start, endd;
bool valid(ll r, ll c) {
    if (r >= m || r < 0 || c >= n || c < 0) return false;
    if (visited[r][c]) return false;
    return true;
}
ll dirx[4] = {0, 0, -1, 1};
ll diry[4] = {1, -1, 0, 0};

void floodfill(ll r, ll c, ll depth) {
    //print_mat(visited);
    paths[r][c]++;
    visited[r][c] = true;
    if (endd.r == r && endd.c == c && depth == total) {
        counter++;
        return;
    } else if (endd.r == r && endd.c == c) {
        return;
    }
    for (const auto & i : checkpoints) {
        if (i.r == r && i.c == c && depth != grid[r][c]) {
            return;
        }
    }
    FOR (i, 0, 4) {
        ll newr = r + dirx[i], newc = c + diry[i];
        if (valid(newr, newc)) {
            floodfill(newr, newc, depth+1);
            visited[newr][newc] = false;
        }
    }
}

void solve(ll m, ll n, ll c) {
    counter = 0;
    total = m * n;
    order_a = total / 4;
    order_b = total / 2;
    order_c = 3 * total / 4;
    for (auto & i : checkpoints) {
        cin >> i.r >> i.c;
    }
    grid.resize(m, vector<ll>(n, 0));
    paths.resize(m, vector<ll>(n, 0));
    visited.resize(m, vector<bool>(n, false));
    grid[m-checkpoints[0].r-1][checkpoints[0].c] = order_a;
    grid[m-checkpoints[1].r-1][checkpoints[1].c] = order_b;
    grid[m-checkpoints[2].r-1][checkpoints[2].c] = order_c;
    
    
    start.r = m-1;
    start.c = 0;
    
    endd.r = m-1;
    endd.c = 1;
    floodfill(m-1, 0, 1);
    cout << "Case " << c << ": " << counter << endl;
    //print_mat(grid);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll c = 1;
    while (true) {
        cin >> m >> n;
        if (m == 0) return 0;
        solve(m, n, c);
        c++;
    }
}