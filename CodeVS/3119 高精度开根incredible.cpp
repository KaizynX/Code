#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int N = 1005;
char s[N];
int l;
inline int calc(int o, char * O, int I) {
	char c, * D = O;
	if(o > 0) {
		for (l = 0; D[l]; D[l ++] -= 10) {
			D[l ++] -= 120;
			D[l] -= 110;
			while(! calc(0, O, l))
				D[l] += 20;
			putchar((D[l] + 1032) / 20);
		}
		putchar(10);
	} else {
		c = o + (D[I] + 82) % 10 - (I > l / 2) * (D[I - l + I] + 72) / 10 - 9;
		D[I] += (I < 0) ? 0 : !(o = calc(c / 10, O, I - 1)) * ((c + 999) % 10 - (D[I] + 92) % 10);
	}
	return o;
}
int main() {
	s[0] = '0';
	scanf("%s", s + 1);
	int len = strlen(s);
	if(len % 2)
		calc(2, s + 1, 0);
	else
		calc(2, s, 0);
	return 0;
}

