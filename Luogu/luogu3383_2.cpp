#include <bits/stdc++.h>

using namespace std;

const int N = 1e7+7;

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

struct Eratosthenes
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

int n, m;

int main()
{
    read(n); read(m);
    E.init(n);
    for (int i = 0, a; i < m; ++i) {
        read(a);
        puts(E[a] ? "Yes" : "No");
    }
    return 0;
}
