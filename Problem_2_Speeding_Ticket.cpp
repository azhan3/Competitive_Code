#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vec = vector<T>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;
template <class T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class R>
using indexed_map =
    tree<K, R, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define PB push_back
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << "ln" << __LINE__ << ": " << #x << " = " << x << endl

template <class T>
string to_string(T s, T e) {
    if (s == e) return "[]";
    string ret = "[" + to_string(*s++);
    while (s != e) ret += ", " + to_string(*s++);
    return ret + "]";
}
void setIO(string s) {
   freopen((s + ".in").c_str(), "r", stdin);
   freopen((s + ".out").c_str(), "w", stdout);
}

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
#define PRECISION ;
//#define FILE ;

#define SINGLE ;
//#define MULTIPLE ;
//#define GOOGLE ;

void solve() {}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setIO("speeding");
    ll n, m, t1, t2, c=0, sped=0;
    cin >> n >> m;
    vll segments;
    FOR(i, 0, n) {
        cin >> t1 >> t2;
        FOR(j, c, c+t1) {
            segments.push_back(t2);
        }
        c+=t1;
    }
    c=0;
    FOR(i, 0, m) {
        cin >> t1 >> t2;
        FOR(j, c, c+t1) {
            if (segments[j] < t2) {
                sped = max(sped, t2- segments[j]);
            }
        }
        c+=t1;
    }
    cout << sped;
    
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
#endif
#ifdef GOOGLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}