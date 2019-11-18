#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T, n;
int s[N];

struct Euler
{
    int phi[N], check[N];
    vector<int> prime;
    void init(int sz) {
        for (int i = 1; i <= sz; ++i) check[i] = 1;
        phi[1] = 1; check[1] = 0;
        for (int i = 2; i <= sz; ++i) {
            if (check[i]) {
                prime.emplace_back(i);
                phi[i] = i-1;
            }
            for (int j : prime) {
                if (i*j > sz) break;
                check[i*j] = 0;
                if (i%j) {
                    phi[i*j] = (j-1)*phi[i];
                } else {
                    phi[i*j] = j*phi[i];
                    break;
                }
            }
        }
    }
} E;

int main()
{
    E.init(1000);
    s[1] = 3;
    for (int i = 2; i <= 1000; ++i)
        s[i] = s[i-1]+E.phi[i]*2;

    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        printf("%d %d %d\n", t, n, s[n]);
    }
    return 0;
}
