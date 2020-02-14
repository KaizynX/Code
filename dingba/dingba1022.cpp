#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

int main()
{
    scanf("%d", &n);
    getchar();
    while (n--) {
        char c;
        int cnt = 0;
        vector<int> res;
        while ((c=getchar()) && c != '.') {
            if (c == ' ') {
                if (cnt) res.emplace_back(cnt);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        getchar();
        if (cnt) res.emplace_back(cnt);
        for (int i = 0; i < (int)res.size(); ++i) {
            if (i) putchar(' ');
            printf("%d", res[i]);
        }
        putchar('\n');
    }
    return 0;
}
