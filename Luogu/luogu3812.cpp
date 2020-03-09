#include <bits/stdc++.h>

using namespace std;

const int N = 60;

template <typename T>
struct XXJ
{
    int sz = sizeof(T)*8;
    vector<T> p;
    XXJ(){ init(); }
    void init() { vector<T>(sz, 0).swap(p); }
    void insert(T x) {
        for (int i = sz-1; i >= 0; --i) {
            if (~(x>>i)&1) continue;
            if (!p[i]) {
                p[i] = x;
                break;
            }
            x ^= p[i];
        }
    }
    template <typename TT>
    void build(TT a[], const int &n) {
        init();
        for (int i = 1; i <= n; ++i) insert(a[i]);
    }
    bool find(const T &x) {
        T now = 0;
        for (int i = sz-1; i >= 0; --i) {
            if (((now>>i)&1)^((x>>i)&1)) {
                if (!p[i]) return false;
                now ^= p[i];
            }
        }
        return true;
    }
    T max_xor() {
        T res = 0;
        for (int i = sz-1; i >= 0; --i) {
            // res = max(res, res^p[i]);
            if ((res>>i)&1) continue;
            res ^= p[i];
        }
        return res;
    }
};

int n;
long long a[N];
XXJ<long long> xxj;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    xxj.build(a, n);
    cout << xxj.max_xor() << endl;
    return 0;
}
