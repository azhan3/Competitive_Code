#include <bits/stdc++.h>  
typedef long long ll;
using namespace std;
void solve(){
    ll x,y,b;
    cin>>x>>y;
    b = x%2==0?y%4>0?y%4>1?y%4>2?x+y/4*4+4:x+1:x-(y/4*4+1):x:y%4>0?y%4>1?y%4>2?x-(y/4*4+4):x-1:x+(y/4*4+1):x;
    cout<<b<<"\n";
}
int main()
{
    ll t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
    return 0;
}
 