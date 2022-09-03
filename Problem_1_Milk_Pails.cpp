#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
	int x, y, m, max_q;
    cin >> x >> y >> m;
    pair <int, int> pails((m - y * (m / y)) / x, m / y);
    max_q = pails.first * x + pails.second * y;
    for(int i = 0 ; i < m/y ; ++i) {
        pails.second--;
        pails.first=((m - y * pails.second) / x);
        max_q = max(pails.first * x + pails.second * y, max_q);
    }
    cout << max_q;
}