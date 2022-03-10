#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    string x;
    cin >> x;
    cout << x.back() << x.substr(1) << endl;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}