#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
    int sum,a;
    cin>>sum;
    for(int i=1;i<=sum;i++){
        cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<endl;
    set<int>::iterator it;
    for(it=s.begin();it !=s.end();it++){
    //for (set<int>::iterator it = s.begin(); it != s.end(); it++)
        cout<<*it<<" ";
    }
    return 0;
}

/*#include <iostream>
#include <set>
//#include <algorithm>
using namespace std;
int main()
{
    set<int>s;
    int n;
    cin >> n;
    int num;
    while (n--){
        cin>>num;
        s.insert(num);
    }
    cout<<s.size()<<endl;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    return 0;
}
*/
