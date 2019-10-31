#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int n, res;
int f[N];

struct Point
{
    int x, y, z, id;
    friend bool operator < (const Point &a, const Point &b) {
        if (a.x != b.x) return a.x < b.x;
        if (a.y != b.y) return a.y < b.y;
        return a.z < b.z;
    }
    friend long long dis(const Point &a, const Point &b) {
        return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y)+1ll*(a.z-b.z)*(a.z-b.z);
    }
} p[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    for (int i = 1; i <= n; ++i) {
        if (f[i]) continue;
        long long mind;
        int mini = -1;
        for (int j = i+1; j <= n; ++j) {
            if (f[j]) continue;
            long long tmp = dis(p[i], p[j]);
            if (mini == -1 || mind > tmp) {
                mind = tmp;
                mini = j;
            }
        }
        cout << i << " " << mini << endl;
        f[i] = f[mini] = 1;
    }
    return 0;
}
