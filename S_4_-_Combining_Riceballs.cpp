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

ll search(vector<ll>rice, ll pos, ll mv) {
    mv = max(mv, rice[pos]);
    if (pos == rice.size()-1) return mv;
    vector<ll>sk2(rice.begin(), rice.end());
    vector<ll>sk3(rice.begin(), rice.end());
    if (pos < rice.size()-2 && rice[pos] == rice[pos + 2]) {
        ll tmp = rice[pos] * 2 + rice[pos+1];
        sk3.erase(sk3.begin()+pos, sk3.begin()+pos+2);
        sk3[pos] = tmp;
        mv = max(mv, search(sk3, max(pos-2, 0LL), mv));
    }
    
    if (pos < rice.size()-1 && rice[pos] == rice[pos+1]) {
        ll tmp = rice[pos] * 2;
        sk2.erase(sk2.begin()+pos);
        sk2[pos] = tmp;
        mv = max(mv, search(sk2, max(pos-2, 0LL), mv));
    }
    mv = max(mv, search(rice, pos+1, mv));
    
    return mv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll>rice(n);
    for (auto & i : rice) cin >> i;
    cout << search(rice, 0, 0) << endl;
}