#include <bits/stdc++.h>
using namespace std;

int Fish() {
    int a,b,c,d;
    string result;
    cin >> a >> b >> c >> d;
    if (a == b == c == d) {
        result = "Fish At Constant Depth";
    } else if (a < b && b < c && c < d) {
        result = "Fish Rising";
    } else if (a > b && b > c && c > d) {
        result = "Fish Diving";
    } else {
        result = "No Fish";
    }
    cout << result;
    return 0;
}