#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T, n, a, b, c, d;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> a >> b >> c >> d >> s;
        int aa = a, bb = b, cc = c, dd = d, res = 0;
        for (char i : s) {
            if (i == '1') {
                if (cc) {
                    --cc;
                    ++res;
                } else if (dd) {
                    --dd;
                    ++cc;
                } else if (aa) {
                    --aa;
                    ++res;
                } else if (bb) {
                    --bb;
                    ++aa;
                }
            } else {
                if (dd) {
                    --dd;
                    ++cc;
                } else if (cc) {
                    ;
                } else if (bb) {
                    --bb;
                    ++aa;
                } else {
                    ;
                }
            }
        }
        cout << res << " ";
        aa = a, bb = b, cc = c, dd = d, res = 0;
        for (char i : s) {
            if (i == '1') {
                if (dd) {
                    --dd;
                    ++cc;
                } else if (cc) {
                    --cc;
                    ++res;
                } else if (bb) {
                    --bb;
                    ++aa;
                } else if (aa) {
                    --aa;
                    ++res;
                }
            } else {
                if (cc) {
                    ;
                } else if (dd) {
                    --dd;
                    ++cc;
                } else if (aa) {
                    ;
                } else if (bb) {
                    --bb;
                    ++aa;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
