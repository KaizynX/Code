#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 3e3+7;

int n, m, k;
int a[N], c[N], p[N];

inline void build()
{
    k = 0;
    for (int i = 1; i <= n; ++i) c[i] = 0;
    for (int i = 1; i <= n; ++i) if (!c[i]) {
        int cur = i;
        ++k;
        while (!c[cur]) {
            c[cur] = k;
            cur = a[cur];
        }
    }
}

inline void my_swap(int i, int j)
{
    swap(a[p[i]], a[p[j]]);
    swap(p[i], p[j]);
    build();
}

#ifdef DEBUG
inline void print()
{
    for (int i = 1; i <= n; ++i)
        cout << c[i] << " \n"[i==n];
}
#endif

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    cin >> m;

    build();
    cout << abs(n-k-m) << endl;
    for (int t = 0, tt = abs(n-k-m); t < tt; ++t) {
#ifdef DEBUG
        print();
#endif
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if ((n-k < m && c[i] == c[j]) ||
                    (n-k > m && c[i] != c[j])) continue;
                cout << i << " " << j << " ";
                my_swap(i, j);
                flag = 1;
                break;
            }
            if (flag) break;
        }
    }
    return 0;
}
