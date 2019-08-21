#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;

int T;
char s[kN];

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%s", s);
        int len=strlen(s);
        if(s[0]=='z'){
            s[0]='b';
            printf("%s\n",s);
            continue;
        } 
        else if(s[len-1]=='z'){
            int flag=0;
            for(int i=0;i<len-1;i++){
                if(s[i]!='y') {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                s[len-1]='b';
                printf("%s\n",s);
            }
            else printf("%s\n",s);
        }
        else{
            printf("%s\n",s);
        }
    }
    return 0;
}
