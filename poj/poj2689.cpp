#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6+7;

struct Euler
{
    int tot;
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

int L, R;
int f[N];
vector<int> v;

int main()
{
    E.init(100000);
    while (scanf("%d %d", &L, &R) == 2) {
        for (int i = 0; i <= R-L; ++i) f[i] = 1;
        if (L == 1) f[0] = 0;
        for (int i = 1; i <= E.tot && E.prime[i] <= R; ++i) {
            for (long long j = L/E.prime[i]*E.prime[i]; j <= R; j += E.prime[i]) {
                if (j > E.prime[i] && j >= L) f[j-L] = 0;
            }
        }
        v.clear();
        for (int i = 0; i <= R-L; ++i) {
            if (f[i]) v.push_back(L+i);
        }
        if (v.size() < 2) {
            puts("There are no adjacent primes.");
            continue;
        }
        int mini = 1, maxi = 1;
        for (int i = 1; i < (int)v.size(); ++i) {
            if (v[i]-v[i-1] < v[mini]-v[mini-1]) mini = i;
            if (v[i]-v[i-1] > v[maxi]-v[maxi-1]) maxi = i;
        }
        printf("%d,%d are closest, %d,%d are most distant.\n",
            v[mini-1], v[mini], v[maxi-1], v[maxi]);
    }
    return 0;
}
