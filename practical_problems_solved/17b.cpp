#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> se;
    int d,i;
    cout<<endl<<"Enter a Decimal no. : ";
    cin>>d;
    for(i=d;i>0;i=i/2)
    {
        se.push(i%2);
    }
    cout<<endl<<"Binary value: ";
    for(;!se.empty();se.pop())
    {
        cout<<se.top();

    }
    return 0;
}

