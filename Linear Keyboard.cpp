#include <bits/stdc++.h>
#include <cstdlib>
typedef long long ll;
using namespace std;

void solve()
{
    string x, y;
    ll z = 0;
    cin >> x;
    cin >> y;
    for (int i = 0; i < y.length(); i++)
    {
        if (i + 1 == y.length())
        {
            break;
        }
        z += abs(int(x.find(y[i + 1]) - x.find(y[i])));
    }
    cout << z << "\n";
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