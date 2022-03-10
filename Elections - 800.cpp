#include <bits/stdc++.h>
using namespace std;
void calculate()
{
    int a,b,c,k;
    cin >> a; cin >> b; cin>>c;
    k=max(max(a,b),c);
    int q = (a!=k) ? k-a+1 : (a==0) ? 1 : (a == b) ? k-a+1 : (a==c) ? k-a+1 : 0;
    int w = (b!=k) ? k-b+1 : (b==0) ? 1 : (b == a) ? k-b+1 : (b==c) ? k-b+1 : 0;
    int e = (c!=k) ? k-c+1 : (c==0) ? 1 : (c == b) ? k-c+1 : (a==c) ? k-c+1 : 0;
    cout<<q<<" "<<w<<" "<<e<<"\n";
}
int main()
{
    int x;
    cin>>x;
    for (int i = 0 ; i<x;i++){
        calculate();
    }
}