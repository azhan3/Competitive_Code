/*
ID: alex.zh5
TASK: "PROBLEM NAME"
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

#define FILE "file"

void solve() {
  
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
