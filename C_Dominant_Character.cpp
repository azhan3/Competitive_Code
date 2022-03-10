#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll x;
    string y;
    vector<ll> ag;
    cin >> x >> y;
 
    if (y.find("aa")!=string::npos)cout<<2<<"\n";
    else if (y.find("aba")!=string::npos)cout<<3<<"\n";
    else if (y.find("aca")!=string::npos)cout<<3<<"\n";
    else if (y.find("abca")!=string::npos)cout<<4<<"\n";
    else if (y.find("acba")!=string::npos)cout<<4<<"\n";
    else if (y.find("abbacca")!=string::npos)cout<<7<<"\n";
    else if (y.find("accabba")!=string::npos)cout<<7<<"\n";
    else cout<<"-1\n";
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}