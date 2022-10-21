#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define dbg(...)
#else
#include "lib/debug.h"
#endif
using ll = long long;
const int MAX_N = 600;
template <class T>
using vec = vector<T>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[MAX_N+1][MAX_N+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll w, l, n;
    cin >> w >> l >> n;
    vector<pair<ll, ll>>slabs(n);
    for (auto & i : slabs) cin >> i.first >> i.second;
        for (int i = 0 ; i <= w; ++i) {
            for (int j = 0 ; j <= l ; ++j) {
                dp[i][j] = i * j; 
            }
    }
    for (auto & i : slabs) {
        dp[i.first][i.second] = 0;
    }
    for (int i = 1 ; i <= w ; ++i) {
        for (int j = 1 ; j <= l ; ++j) {
            for (int x = 1 ; x <= i ; ++x) {
                dp[i][j] = min(dp[i][j], dp[x][j] + dp[i - x][j]);
            }
            for (int y = 1 ; y <= j ; ++y) {
                dp[i][j] = min(dp[i][j], dp[i][y] + dp[i][j - y]);
            }
        }
    }
    cout << dp[w][l] << endl;
}