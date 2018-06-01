#include <iostream>
#include <cstring>
using namespace std;
int NP,qian,ren;
int money[10]={0};
string name[10],mz1,mz2;

int fname(string mingzi)
{
    for(int i=0;i<NP;i++)
    {
        if(name[i]==mingzi)
        {
            return i;
        }
    }
}

int main()
{

    cin>>NP;
    for(int i=0;i<NP;i++)cin>>name[i];
    for(int i=0;i<NP;i++)
    {
        cin>>mz1>>qian>>ren;
        for(int j=0;j<ren;j++)
        {
            cin>>mz2;
            money[fname(mz1)]-=qian/ren;
            money[fname(mz2)]+=qian/ren;
        }
    }
    for(int i=0;i<NP;i++)
    {
        cout<<name[i]<<" "<<money[i]<<endl;
    }
    return 0;
}
