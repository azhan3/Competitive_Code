#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int x;
    string y;
    cin >> x;
    cin >> y;
    for (char &c : y)
    {
        if (c == 'U')
        {
            cout << "D";
            continue;
        }
        else if (c == 'D')
        {
            cout << "U";
            continue;
        }
        else
        {
            cout << c;
        }
    }
    cout << "\n";
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