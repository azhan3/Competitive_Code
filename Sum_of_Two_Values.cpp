#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAX_N = 1e5;
template <class T>
using vec = vector<T>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define dbg(x) cerr << "ln" << __LINE__ << ": " << #x << " = " << x << endl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t, in;
    cin >> n >> t;
    vector <ll> a(n);
    map<ll, ll>pos;
    for (auto & i : a) {
        cin >> i;
    }
    FOR(i, 0, n) {
        if (pos.count(a[i])) {
            cout << pos[a[i]] + 1 << " " << i + 1;
            return 0;
        }
        pos[t - a[i]] = i;
    }
    cout << "IMPOSSIBLE";
}