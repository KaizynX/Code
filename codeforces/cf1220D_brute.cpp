#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n;
int check[N];

int main() 
{
    cin >> n;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        if (i == 1) {
            for (int j = 0; j < a; ++j) {
                for (int k = j+1; k < N; k += a) {
                    check[k] = check[k-a]^1;
                }
            }
        } else {
            for (int j = 0; j < a; ++j) {
                for (int k = j; k+a < N; k += a) {
                    if (check[k] != check[k+a]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
