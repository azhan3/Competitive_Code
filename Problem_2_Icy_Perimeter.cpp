#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define dbg(...)
#else
#include "lib/debug.h"
#endif

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vec = vector<T>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vector<ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
template <class T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class R>
using indexed_map =
    tree<K, R, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (const auto & a : c)
#define all(x) x.begin(), x.end()

void setIO(string s) {
   freopen((s + ".in").c_str(), "r", stdin);
   freopen((s + ".out").c_str(), "w", stdout);
}

#define MOD 1000000007
//#define MOD 998244353

#define FASTIO
#define PRECISION

#define SINGLE
//#define MULTIPLE
//#define GOOGLE

struct grid {
  ll n, curperi, curarea, area=0,perimeter=0;
  pair<ll, ll> largest_i = {NULL, 0};
  vector<vector<char>>ice;
  vector<vector<bool>>visited;
  char ch = '#';
  grid(ll n) {
    ice.resize(n, vector<char>(n));
    visited.resize(n, vector<bool>(n, false));
    this->n = n;
  }
  void solvee() {
    FOR(i, 0, n) {
      FOR(j, 0, n) {
        if (visited[i][j] || ice[i][j] != ch) continue;
        curarea=0;
        curperi=0;
        floodfill(i, j, ch);
        if (curarea == area) {
            perimeter = min(perimeter, curperi);
        } else if (curarea > area) {
            perimeter = curperi;
            area = curarea;
        }
      }
    }
    cout << area << " " << perimeter << "\n";
  }

  void floodfill(ll r, ll c, ll ch) {
    if (r < 0 || r >= n || c < 0 || c >= n || ice[r][c] != ch) {
        curperi++;
        return;
    }
    if (visited[r][c]) return;
    visited[r][c] = true;
    curarea++;
    floodfill(r, c+1, ch);
    floodfill(r, c-1, ch);
    floodfill(r+1, c, ch);
    floodfill(r-1, c, ch);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  setIO("perimeter");
  ll n;
  cin >> n;
  grid ice_cream(n);
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      cin >> ice_cream.ice[i][j];
    }
  }
  ice_cream.solvee();
  return 0;
}