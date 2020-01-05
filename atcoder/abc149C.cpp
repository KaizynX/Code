#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

struct Euler
{
    int tot = 0;
    int prime[N];
    bool check[N];
    bool& operator [] (const int i) { return check[i]; }
    void init(int sz) {
        tot = 0;
        for (int i = 1; i <= sz; ++i) check[i] = true;
        check[1] = false;
        for (register int i = 2, j; i <= sz; ++i) {
            if (check[i]) prime[++tot] = i;
            for (j = 1; j <= tot && i*prime[j] <= sz; ++j) {
                check[i*prime[j]] = false;
                if (i%prime[j] == 0) break;
            }
        }
    }
} E;

int x;

int main()
{
    cin >> x;
    E.init(1e5+3);
    for (int i = 1; i <= E.tot; ++i) {
        if (E.prime[i] >= x) {
            cout << E.prime[i] << endl;
            return 0;
        }
    }
    return 0;
}

