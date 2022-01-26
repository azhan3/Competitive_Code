#include <bits/stdc++.h>
using namespace std;

int Gates() {
    int x,y;
    cin >> x >> y;
    vector <int> planes(y);
    vector <bool> gates;
    vector <int> planesCanFit(y);
    int planeCounter = 0;
    gates.insert(gates.end(), x, true);
    for (int i = 0; i < y; ++i) {
        cin >> planes[i];
    }
    for (int i = 0; i < y; i++) {
        bool quit = false;
        for (int j = planes[i] - 1 ; j >= 0 ; j--) {
            if (gates[j]) {
                gates[j] = !gates[j];
                planeCounter++;
                break;
            } else if (j == 0) {
                quit = true;
            }
        }
        if (quit) {
            break;
        }
    }
    cout << planeCounter<<endl;
    return 0;
}