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

void solve() {
    string x;
    cin >> x;
    ll n = x.size();
    bool f = false;
    ll max_idx = -1;
    FOR (i, 0, n) {
        ll j = n - i - 1;
        if ((x[j]-'0')>=5) {
            if (j == 0) {
                f = true;
                x[j] = '0';
                max_idx = 0;
                break;
            }
            max_idx = j;
            x[j] = '0';
            x[j-1] = char(x[j-1] + 1);
        }
    }

    if (f) cout << 1;
    FOR(i, 0, n) {
        if (i >= max_idx && max_idx != -1) cout << 0;
        else cout << x[i];
    }
    cout << endl;
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