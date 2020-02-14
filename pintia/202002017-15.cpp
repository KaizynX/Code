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
    for (int i = 1, k; i <= n; ++i) {
        c1.clear(); c2.clear();
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
        int cnt = 0;
        for (pii p1 : c1)
            for (pii p2 : c2)
                if (p1 == p2) {
                    ++cnt;
                    break;
                }
        if (cnt != 2) {
            cout << "NO" << endl;
            continue;
        }
        c1.insert(c1.end(), c2.begin(), c2.end());
        c1.erase(unique(c1.begin(), c1.end()), c1.end());
        vector<int>(c1.size(), 0).swap(vis);
        for (int i = 0; i < (int)c1.size(); ++i)
            for (int j = i+1; j < (int)c1.size(); ++j)
                for (k = j+1; k < (int)c1.size(); ++k)
                    line(i, j, k);
        for (int i = c2.size()-1; i >= 0; --i)
            if (vis[i]) c1.erase(c1.begin()+i);
        if (c1.size() != 4 || !check()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
