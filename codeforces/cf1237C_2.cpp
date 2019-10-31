#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+7;


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

bool cmpx(const Point &a, const Point &b) { return a.x < b.x; }
bool cmpy(const Point &a, const Point &b) { return a.y < b.y; }
bool cmpz(const Point &a, const Point &b) { return a.z < b.z; }

int n;
int f[N];
map <pair<int, int>, vector<Point> > mpxy, mpxz, mpyz;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        p[i].id = i;
        cin >> p[i].x >> p[i].y >> p[i].z;
        mpxy[{p[i].x, p[i].y}].push_back(p[i]);
        mpxz[{p[i].x, p[i].z}].push_back(p[i]);
        mpyz[{p[i].y, p[i].z}].push_back(p[i]);
    }
    for (auto p : mpxy) {
        vector<Point> &vec = p.second;
        if (vec.size() < 2) continue;
        sort(vec.begin(), vec.end(), cmpz);
        for (int i = 0, j; i < (int)vec.size()-1; ++i) {
            if (f[vec[i].id]) continue;
            j = i+1;
            while (j < (int)vec.size() && f[vec[j].id]) ++j;
            if (j == (int)vec.size()) continue;
            cout << vec[i].id << " " << vec[j].id << endl;
            f[vec[i].id] = f[vec[j].id] = 1;
        }
    }
    for (auto p : mpxz) {
        vector<Point> &vec = p.second;
        if (vec.size() < 2) continue;
        sort(vec.begin(), vec.end(), cmpy);
        for (int i = 0, j; i < (int)vec.size()-1; ++i) {
            if (f[vec[i].id]) continue;
            j = i+1;
            while (j < (int)vec.size() && f[vec[j].id]) ++j;
            if (j == (int)vec.size()) continue;
            cout << vec[i].id << " " << vec[j].id << endl;
            f[vec[i].id] = f[vec[j].id] = 1;
        }
    }
    for (auto p : mpyz) {
        vector<Point> &vec = p.second;
        if (vec.size() < 2) continue;
        sort(vec.begin(), vec.end(), cmpx);
        for (int i = 0, j; i < (int)vec.size()-1; ++i) {
            if (f[vec[i].id]) continue;
            j = i+1;
            while (j < (int)vec.size() && f[vec[j].id]) ++j;
            if (j == (int)vec.size()) continue;
            cout << vec[i].id << " " << vec[j].id << endl;
            f[vec[i].id] = f[vec[j].id] = 1;
        }
    }
    sort(p+1, p+n+1);
    for (int i = 1, j; i < n; ++i) {
        if (f[p[i].id]) continue;
        j = i+1;
        while (j <= n && f[p[j].id]) ++j;
        if (j > n) continue;
        cout << p[i].id << " " << p[j].id << endl;
        f[p[i].id] = f[p[j].id] = 1;
    }
    return 0;
}
