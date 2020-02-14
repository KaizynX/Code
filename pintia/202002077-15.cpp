#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
mt19937 rnd(time(NULL));

int n;

struct Point
{
    int x, y;
    friend bool operator < (const Point &p1, const Point &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    }
    friend istream& operator >> (istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
} a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cout << rnd()%2 << endl;
    return 0;
}
