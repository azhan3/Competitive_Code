#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
	int x, y;
	cin >> x;
	cin >> y;

	int i = (x % 2 != 0) ? floor(y / (x - floor(x / 2))) : floor(y / (x - floor(x / 2 - 1)));
	cout << i << "\n";
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