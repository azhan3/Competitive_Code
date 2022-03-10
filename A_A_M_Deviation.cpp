#include <bits/stdc++.h>  
using namespace std;
 
void solve(){
    int x,y,z; cin>>x>>y>>z;
    cout<<((x+z-2*y)%3==0 ? 0 : 1)<<"\n";   
}
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}