#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int n,fen,ban,lun;
    char gan,xi;
    string name[100];
    int money[100]={0};
    int maxmon=0,monsum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
        cin>>fen>>ban>>gan>>xi>>lun;
        if(fen>80&&lun>=1)money[i]+=8000;
        if(fen>85&&ban>80)money[i]+=4000;
        if(fen>90)money[i]+=2000;
        if(fen>85&&xi=='Y')money[i]+=1000;
        if(ban>80&&gan=='Y')money[i]+=850;

        monsum+=money[i];
        maxmon=max(maxmon,money[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(money[i]==maxmon)
        {
            cout<<name[i]<<endl<<maxmon<<endl<<monsum<<endl;
        }
    }
    return 0;
}
