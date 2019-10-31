#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int n, res, resi, resj;
char str[N];
int s[N], a[N];

int main()
{
    scanf("%d%s", &n, str+1);
    int check = 0;
    for (int i = 1; i <= n; ++i) {
        s[i] = str[i] == '(' ? 1 : -1;
        check += s[i];
    }
    if (check) return printf("0\n1 1\n")&0;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            swap(s[i], s[j]);
            int mina = n, cnt = 0;
            for (int k = 1; k <= n; ++k) {
                a[k] = a[k-1]+s[k];
                if (a[k] < mina) {
                    mina = a[k];
                    cnt = 1;
                } else if (a[k] == mina) {
                    ++cnt;
                }
            }
            if (cnt > res) {
                res = cnt;
                resi = i;
                resj = j;
            }
            swap(s[i], s[j]);
        }
    }
    printf("%d\n%d %d\n", res, resi, resj);
    return 0;
}
