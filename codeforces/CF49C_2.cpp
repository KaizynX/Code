#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e6+7;
/*     p^2 / S
 * ==> (2a+2b)^2 / ab
 * ==> a^2+b^2+2ab / ab
 * ==> a/b + b/a + 2
 * ==> define a < b
 *     if   bi/ai < bj/aj
 *     ==> bi*aj < bj*ai
 *     then choose i
 */
int T, n, tot;
int a[Maxn], b[Maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		tot = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", a+i);
		sort(a+1, a+n+1);
		for(int i = 2; i <= n; ++i)
			// two same length make a pair
			if(a[i] == a[i-1])
			{
				b[++tot] = a[i];
				// delete the two
				a[i] = a[i-1] = -1;
			}
		int res = 2;
		// answer is b[res] and b[res-1]
		for(int i = 3; i <= tot; ++i)
			if(1ll*b[res]*b[i-1] > 1ll*b[res-1]*b[i])
				res = i;
		printf("%d %d %d %d\n", b[res], b[res], b[res-1], b[res-1]);
	}
	return 0;
}
