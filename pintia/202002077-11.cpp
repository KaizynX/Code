#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m;
map<int, int> pos;

struct Heap
{
    static const int Maxn = 1e6+7;
    int sz, a[Maxn];
    Heap() { sz = 0; memset(a, 0, sizeof a); }
    inline bool cmp(int x, int y) { return x < y; } // Ð¡¸ù¶Ñ
    inline int size() { return sz; }
    inline bool empty() { return sz == 0; }
    inline int top() { return a[1]; }
    inline void push(int x) { a[++sz] = x; pos[x] = sz; swift_up(sz); }
    inline void pop() { swap(a[1], a[sz--]); swift_down(1); }
    inline void swift_up(int p)
    {
        while(p > 1 && cmp(a[p], a[p>>1])) // a[p] < a[p<<1]
            swap(a[p], a[p>>1]), swap(pos[a[p]], pos[a[p>>1]]), p >>= 1;
    }
    inline void swift_down(int p)
    {
        int l, r, s;
        while(true)
        {
            l = p<<1; r = p<<1|1;
            if(l > sz) break;
            if(r > sz || cmp(a[l], a[r])) s = l; // a[l] < a[r]
            else s = r;
            if(cmp(a[s], a[p])) // a[s] < a[p]
                swap(a[p], a[s]), p = s;
            else break;
        }
    }
} HP;

int main()
{
    cin >> n >> m;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        HP.push(a);
    }
    cin.get();
    while (m--) {
        int x, y, flag;
        string s;
        stringstream ss;
        getline(cin, s);
        ss << s;
        ss >> x >> s;
        if (s == "is") {
            ss >> s;
            if (s == "the") {
                ss >> s;
                if (s == "root") flag = pos[x] == 1;
                else if (s == "parent") {
                    ss >> s >> y;
                    flag = pos[y]/2 == pos[x];
                }
            } else if (s == "a") {
                ss >> s >> s >> y;
                flag = pos[x]/2 == pos[y];
            }
        } else if (s == "and") {
            ss >> y;
            flag = abs(pos[x]-pos[y]) == 1 && pos[x]/2 == pos[y]/2;
        }
        //cout << x << " " << y << " ";
        //cout << pos[x] << " " << pos[y] << endl;
        cout << (flag ? "T" : "F") << endl;
    }
    return 0;
}
