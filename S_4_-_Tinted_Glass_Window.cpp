#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define dbg(...)
#else
#include "lib/debug.h"
#endif
using ll = long long;
const int MAX_N = 1e5;
template <class T>
using vec = vector<T>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
const int N = 2e3 + 10;

unordered_map<ll, int> MapX, MapY;
ll t;
int n;
struct windows{
    ll x1, x2, y1, y2;
    int c;
}w[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    vector<ll>x(n*4+1), y(n*4+1), getX(n*4+1), getY(n*4+1);
    vector<vector<ll>>Map(n*4+1, vector<ll>(n*4+1));
    int xlen = 0;
    int ylen = 0;
    for(int i = 1;i<=n;i++){
        cin>>w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2 >> w[i].c;
        x[++xlen] = w[i].x1;
        x[++xlen] = w[i].x2;
        y[++ylen] = w[i].y1;
        y[++ylen] = w[i].y2;
    }
    dbg(x, y);
    sort(x.begin()+1, x.begin() + xlen+1);
    sort(y.begin()+1, y.begin() + ylen+1);
    
    int len1 = 0;
    int len2 = 0;
    for(int i = 1;i<=xlen;i++){
        if(MapX[x[i]] == 0) {
            MapX[x[i]] = ++len1;
            getX[len1] = x[i];
        }
    }
    for(int i = 1;i<=ylen;i++){
        if(MapY[y[i]] == 0){
            MapY[y[i]] = ++len2;
            getY[len2] = y[i];
        }
    }
    dbg(MapX, MapY);
    for(int i = 1;i<=n;i++){
        int lx = MapX[w[i].x1];
        int rx = MapX[w[i].x2];
        if(lx > rx) swap(lx, rx);
        int ly = MapY[w[i].y1];
        int ry = MapY[w[i].y2];
        if(ly > ry) swap(ly, ry);
        int c = w[i].c;
        for(int j = lx + 1; j<= rx;j++){
            for(int k = ly + 1; k<= ry;k++){
                Map[j][k] += c;
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i<=len1;i++){
        for(int j = 1;j<=len2;j++){
            if(Map[i][j] >= t){
                ans += (getX[i] - getX[i - 1]) * (getY[j] - getY[j - 1]);
            }
        }
    }
    dbg(x, getX, y, getY, MapX, MapY, Map);
    cout<<ans<<endl;
    return 0;
}