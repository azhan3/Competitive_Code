#include <bits/stdc++.h>
using namespace std;

void solve() {
    string x;
    cin>>x;
    vector<char>chars(x.begin(), x.end());
    sort(chars.begin(), chars.end());
    for (auto&i : chars) {
        cout<<i;
    }
    cout<<endl;
}

int Equidistant() {
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)solve();
    return 0;
}