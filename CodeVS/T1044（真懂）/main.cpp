#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int h[21],lie[21]={0};
    int flag=1,len=0;
    lie[0]=30001;//无穷大
    while(cin>>h[flag])flag++;
    flag--;
    //最长下降
    for(int i=1;i<=flag;i++)
    {
        if(h[i]<lie[len])lie[++len]=h[i];
        else
        {
            for(int j=1;j<=len;j++)
            {
                if(h[i]>lie[j])
                {
                    lie[j]=h[i];
                    break;
                }
            }
        }
    }
    cout<<len<<endl;
    //最长上升
    memset(lie,1,sizeof(lie));
    lie[0]=0;//无穷小
    len=0;
    for(int i=1;i<=flag;i++)
    {
        if(h[i]>lie[len])lie[++len]=h[i];
        else
        {
            for(int j=1;j<=len;j++)
            {
                if(h[i]<lie[j])
                {
                    lie[j]=h[i];
                    break;
                }
            }
        }
    }
    cout<<len<<endl;
    return 0;
}
