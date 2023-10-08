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
    ll n;
    cin >> n;
    vector<ll>a(n+1);

    FOR(i, 0, n) {
        ll x;
        cin >> x;
        a[x]++;
    }
    ll dif = 0, sam=0;
    FOR(i, 0, n+1) {
        if (a[i] != 0) dif++;
        if(a[i] > sam) {
            sam = max(sam, a[i]);
        }
    }
    if (dif == sam) {
        dif--;
    }
    cout << min(dif, sam) << endl;

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