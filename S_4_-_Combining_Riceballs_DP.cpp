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
    ll n, mv=0;
    cin >> n;
    
    vector<vector<ll>>dp(n+1, vector<ll>(n+1));
    vector<ll>sum(n+1);
    vector<vector<bool>>possible(n+1, vector<bool>(n+1));
    FOR (i, 1, n+1) {
        cin >> dp[i][i];
        sum[i] = dp[i][i] + sum[i-1];
        possible[i][i] = true;
    }


    FOR (l, 2, n+1) {
        FOR (i, 1, n+1) {
            
            ll j = i + l - 1;
            
            if (j > n) continue;
            //dbg("--------------", i, j, "--------------");
            FOR (k, i, j) {
                //dbg(k);
                if (possible[i][k] && possible[k+1][j] && dp[i][k] == dp[k+1][j]) {
                    dp[i][j] = sum[j] - sum[i-1];
                    possible[i][j] = true;
                } else if (k != i) {
                    FOR (u, i, k) {
                        //dbg(u);
                        if (possible[i][u] && possible[u+1][k] && possible[k+1][j] && dp[i][u] == dp[k+1][j]) {
                            dp[i][j] = sum[j] - sum[i-1];
                            possible[i][j] = true;
                        }
                    }
                }
                
            }
        }
    }
    for (auto & i : dp) {
        for (auto & j : i) mv = max(mv, j);
    }
    dbg(sum, dp, possible);
    cout << mv << endl;
}