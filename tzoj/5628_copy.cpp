#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,E1,E2,E3,t,h;
    while(~scanf("%d",&n),n){
        scanf("%d%d%d",&E1,&E2,&E3);
        int ans=0;
        while(n--){
            scanf("%d%d",&t,&h);
            int maxx=0,el=0;
            for(int i=1;i<=h;i++){
				// t/25 ����
				// ÿ�������ƶ�2*i, �����õ�1
                el+=(2*i+1)*t/25;
				// i*t ��ǰ��ȹ����
				// 2*(i+1) �ƶ�+���� ʱ��
                maxx=max(maxx,i*t-(min(2*(i+1)*E3,E1)+el+t*i/25*2*E2+E1));
            }
            ans+=maxx;
        }
        printf("%d\n",ans);
    }
    return 0;
}
