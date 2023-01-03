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
    ll n;
    cin >> n;
    vector<ll>a(n);
    for (auto & i : a) cin >> i;
    vector<ll>dp(n+1, 1e9);
    dp[0] = 20;
    FOR(i, 1, n+1) {
        dp[i] = min(dp[i-1] + 20, dp[upper_bound(a.begin(), a.begin() + i + 1, a[i-1] - 90) - a.begin()] + 50);

        dp[i] = min(dp[i], dp[upper_bound(a.begin(), a.begin() + i + 1, a[i] - 1440) - a.begin()] + 120);
    }
    dbg(dp);
    FOR (i, 0, n) {
        cout << dp[i+1] - dp[i] << endl;
    }
}