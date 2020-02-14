#include <bits/stdc++.h>

using namespace std;

const int N = 30;
typedef pair<int, int> pii;

int n;
vector<int> vis;
vector<pii> c1, c2;

struct Vector
{
    int x, y;
    Vector(){}
    Vector(const pii &p1, const pii &p2) {
        x = p2.first-p1.first;
        y = p2.second-p1.second;
        int g = __gcd(abs(x), abs(y));
        x /= g; y /= g;
        if (x < 0) x = -x, y = -x;
    }
    friend bool operator == (const Vector &v1, const Vector &v2) {
        return v1.x == v2.x && v1.y == v2.y;
    }
    friend int operator * (const Vector &v1, const Vector &v2) {
        return v1.x*v2.x+v1.y*v2.y;
    }
};

inline void line(int i, int j, int k)
{
    static vector<int> tmp;
    vector<int>(3).swap(tmp);
    tmp[0] = c1[i]; tmp[1] = c1[j]; tmp[2] = c1[k];
    sort(tmp.begin(), tmp.end());
    if (Vector(tmp[0], tmp[1]) == Vector(tmp[1], tmp[2]))
        vis[] = 1;
}

inline bool check()
{
    static vector<Vector> tmp;
    int pingxing = 0, chuizhi = 0;
    tmp.clear();
    for (int i = 0; i < (int)c1.size(); ++i)
        for (int j = i+1; j < (int)c1.size(); ++j)
            tmp.emplace_back(Vector(c1[i], c1[j]));
    return false;
}

int main()
{
    cin >> n;
    for (int i = 1, k, flag; i <= n; ++i) {
        c1.clear(); c2.clear();
        flag = 1;
        cin >> k;
        for (int j = 1, x, y; j <= k; ++j) {
            cin >> x >> y;
            c1.emplace_back(x, y);
        }
        cin >> k;
        for (int j = 1, x, y; j <= k; ++j) {
            cin >> x >> y;
            c2.emplace_back(x, y);
        }
        int p1 = -1, p2 = -1;
        for (int i = 0; i < (int)c1.size()-1; ++i) {
            for (int j = 0; j < (int)c2.size(); ++j)
                if (c1[i] == c2[j])
                    p1 = j;
            if (p1 == -1) continue;
            if (j+1 < (int)c2.size() && c1[i+1] == c2[j+1]) p2 = j+1;
            if (j-1 >= 0 && c1[i+1] == c2[j-1]) {
                reverse(c2.begin(), c2.end());
                for (int j = 0; j < (int)c2.size(); ++j)
                    if (c1[i] == c2[j])
                        p1 = j;
                p2 = j+1;
            }
        }
        if (p1 == -1) flag = 0;
    }
    return 0;
}
