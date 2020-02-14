#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, x;

inline bool check(int x)
{
    return x/100000+x/10000%10+x/1000%10 == x/100%10+x/10%10+x%10;
}

int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        cout << (check(x) ? "You are lucky!" : "Wish you good luck.") << endl;
    }
    return 0;
}
