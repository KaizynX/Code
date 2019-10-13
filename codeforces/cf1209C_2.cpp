#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;
const int INF = 1e9;

int n, T;
char d[MAXN];
int res[MAXN];

inline void print()
{
    for (int i = 0; i < n; ++i)
        printf("%d", res[i]);
    putchar('\n');
}

inline bool check()
{
    int last1 = -1, last2 = -1;
    for (int i = 0; i < n; ++i) {
        if (res[i] == 1) {
            if (last1 == -1) last1 = d[i];
            else if (d[i] >= last1) last1 = d[i];
            else return false;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (res[i] == 2) {
            if (last2 == -1) {
                last2 = d[i];
                if (last2 < last1) return false;
            }
            else if (d[i] >= last2) last2 = d[i];
            else return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, d);
        int last1 = d[n-1], last2 = -1, flag = 1;
        res[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            if (d[i] <= last1) last1 = d[i], res[i] = 1;
            else if (d[i] > last1) {
                res[i] = 2;
                if (last2 == -1) last2 = d[i];
                else if (last2 >= d[i]) last2 = d[i];
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if (!flag) puts("-");
        else {
            if (last2 == -1 || check()) {
                print();
                continue;
            }

            for (int i = 0; i < n; ++i) {
                if (res[i] == 1 && d[i] > last2)
                    res[i] = 2;
            }

            if (check()) print();
            else puts("-");
        }
    }
    return 0;
}
