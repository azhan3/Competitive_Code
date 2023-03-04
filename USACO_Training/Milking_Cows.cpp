/*
ID: alex.zh5
TASK: milk2
LANG: C++  
*/

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

#define f first
#define s second

#define FILE "milk2"

void solve() {
    ll n;
    cin >> n;
    vector <pair<ll, ll>>fa(n);
    for (auto & i : fa) {
        cin >> i.f >> i.s;
    }
    sort(fa.begin(), fa.end());
    ll start = fa[0].f, curend = fa[0].s, tmp = curend - start;
    ll tmp2 = 0, until=fa[0].s;
    FOR(j, 0, n) {
        if (fa[j].f > curend) {
            tmp = max(tmp, curend - start);
            start = fa[j].f;
        }
        if (until < fa[j].f) {
            tmp2 = max(fa[j].f - until, tmp2);
        }
        curend = max(curend, fa[j].s);
        until = max(fa[j].s, until);
    }
    cout << tmp << " " << tmp2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef FILE
      freopen((FILE + string(".in")).c_str(), "r", stdin);
      freopen((FILE + string(".out")).c_str(), "w", stdout);
    #endif
    solve();
    return 0;
}
