#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

struct Point
{
    int x, y;
    friend Point operator - (const Point &p1, const Point &p2) {
        Point res;
        res.x = p1.x-p2.x;
        res.y = p1.y-p2.y;
        return res;
    }
    friend Point operator - (const Point &p) {
        Point res;
        res.x = -p.x;
        res.y = -p.y;
        return res;
    }
    friend bool operator == (const Point &p1, const Point &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    friend bool operator != (const Point &p1, const Point &p2) {
        return p1.x != p2.x || p1.y != p2.y;
    }
    friend istream& operator >> (istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
} p[N], b[N];

int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    if (n&1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        b[i] = p[(i+1)%n]-p[i];
    }
    for (int i = 0; i < n/2; ++i) {
        if (b[i] != -b[i+n/2]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
