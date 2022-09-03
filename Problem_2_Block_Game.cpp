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

template<typename T>
 void Print_Vector(vector<T>& vec) {
  for (const auto& element : vec) cout << element << " ";
  cout << "\n";
}
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
#define PRECISION ;
//#define FILE ;

#define SINGLE ;
//#define MULTIPLE ;
//#define GOOGLE ;

void solve() {
    setIO("blocks");
    string a, b;
    ll n; cin >> n;
    map<char, ll>letters;
    char cur = 'a';
    FOR (i, 0, 26) letters[cur++] = 0;
    FOR (i, 0, n) {
        cin >> a >> b;
        cur = 'a';
        FOR (j, 0, 26) {
            letters[cur] += max(count(all(a), cur), count(all(b), cur));
            cur++;
        }
    }
    for (const auto& i : letters) {
        cout << i.second << "\n";
    }
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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