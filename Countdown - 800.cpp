#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
void solve()
{

    ll k = 0, h, a, g = 0;
    string b;
    cin >> a;
    cin >> b;
    for (char &c : b)
    {
        g++;
        if (g == b.length())
        {
            if (c != 48)
            {
                k += (c - '0');
                break;
            }
            else
            {
                break;
            }
        }
        if (c != 48)
        {
            k = k + (c - '0');
            k++;
        }
    }
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
    return 0;
}