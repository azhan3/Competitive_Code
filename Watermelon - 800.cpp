#include <iostream>
#include <string>
using namespace std;
int main() {
    int x;
    cin>>x;
    string r=(x%2==0) ? (x/2!=1) ? "YES" : "NO" : "NO";
    cout<<r;
}