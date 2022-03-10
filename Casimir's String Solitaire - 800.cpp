#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string x, k;

    cin >> x;
    int a = count(x.begin(), x.end(), 'A');
    int b = count(x.begin(), x.end(), 'B');
    int c = count(x.begin(), x.end(), 'C');

    k = (b == a + c) ? "YES" : "NO";
    cout << k << "\n";
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}