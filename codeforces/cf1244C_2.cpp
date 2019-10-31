#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

long long n, p;
int a, b;

int exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return a; }
    int res = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return res;
}

int main()
{
    cin >> n >> p >> a >> b;
    int x, y;
    int g = exgcd(a, b, x, y), ag = a/g, bg = b/g;
    // ax+by = gcd(a, b);
    if (p%g) { cout << -1 << endl; return 0; }
    long long xx = p/g*x, yy = p/g*y, cg;
#ifdef DEBUG
    cout << xx << " " << yy << endl;
#endif
    // turn xx,yy to be +
    if (xx < 0) {
        cg = -xx/bg+(xx%bg != 0);
        xx += cg*bg;
        yy -= cg*ag;
    }
    if (yy < 0) {
        cg = -yy/ag+(yy%ag != 0);
        xx -= cg*bg;
        yy += cg*ag;
    }
#ifdef DEBUG
    cout << xx << " " << yy << endl;
#endif
    if (xx < 0 || yy < 0) { cout << -1 << endl; return 0; }
    cg = yy/ag;
    xx += cg*bg;
    yy -= cg*ag;
    if (xx+yy > n) { cout << -1 << endl; return 0; }
    cout << xx << " " << yy << " " << n-xx-yy << endl;
    return 0;
}
