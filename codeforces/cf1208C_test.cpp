#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+7;

int n;
int a[MAXN];

inline bool check(int a[])
{
    int flag = 0;
    for (int i = 0; i < n; ++i) flag ^= a[i];

    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        for (int j = 0; j < n; ++j) {
            tmp ^= a[i*n+j];
        }
        if (tmp != flag) return false;
    }
    for (int j = 0; j < n; ++j) {
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp ^= a[i*n+j];
        }
        if (tmp != flag) return false;
    }
    return true;
}

inline void print(int a[])
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i*n+j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main()
{
    cin >> n;
    for (int i = 0; i < n*n; ++i) {
        cin >> a[i];
    }
    if (check(a)) print(a);
    return 0;
}
