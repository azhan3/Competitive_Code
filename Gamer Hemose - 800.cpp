#include <bits/stdc++.h>
typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

int findNthLargestElement(vector<int> &v, int nthLargestElement)
{
    sort(v.begin(), v.end());
    return v[v.size() - nthLargestElement];
}
void solve()
{
    vector<int> g1;
    ll a, b, c;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        cin >> c;
        g1.push_back(c);
    }
    ll u;
    ll l = *max_element(g1.begin(), g1.end());
    ll sl = findNthLargestElement(g1, 2);
    ll h = 2 * (b / (l + sl));
    ll y = b % (l + sl);
    if (y == 0)
    {
        u = h;
    }
    else if (y <= l)
    {
        u = h + 1;
    }
    else if (y <= (l + sl))
    {
        u = h + 2;
    }

    cout << u;
}
int main()
{
    int test;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        solve();
        cout << "\n";
    }

    return 0;
}