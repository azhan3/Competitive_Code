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

    ll l, n1, n2, ans=0;
    cin >> l >> n1 >> n2;
    vector<pair<ll, ll>>a(n1), b(n2);
    for (auto & i : a) cin >> i.first >> i.second;
    for (auto & i : b) cin >> i.first >> i.second;
    ll pta = 0, ptb = 0, cnta=0, cntb=0;

    FOR(i, 0, n1 + n2) {
        ll toa = cnta + a[pta].second;
        ll tob = cntb + b[ptb].second;
        if (a[pta].first == b[ptb].first) {
            if (min(toa, tob) - max(cnta, cntb) >0) ans += min(toa, tob) - max(cnta, cntb);
        } 
        if (toa == tob && toa == l) {
            break;
        }

        if (toa == tob) {
            cnta += a[pta].second;
            cntb += b[ptb].second;
            pta ++;
            ptb ++;
        } else if (toa > tob) {
            cntb += b[ptb].second;
            ptb ++;
        } else {
            cnta += a[pta].second;
            pta ++;
        }
    }
    cout << ans << endl;
}