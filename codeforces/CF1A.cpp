#include <iostream>

using namespace std;

int n, m, a;

int main()
{
    cin >> n >> m >> a;
    cout << (long long)(n/a+(n%a ? 1 : 0)) * (m/a+(m%a ? 1 : 0)) << endl;
    return 0;
}
