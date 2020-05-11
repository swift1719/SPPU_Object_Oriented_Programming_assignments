#include<iostream>
#include<stack>
using namespace std;
void display(stack<int> &q)
{
   cout<<endl<<"SUM : ";
   while(!q.empty())
   {
       cout<<q.top();
       q.pop();
   }
}
stack<int> read()
{
    stack<int> s;
    char c[40];
    cout<<endl<<"Enter a binary no.: ";
    cin>>c;
    for(int i=0;c[i]!='\0';i++)
    {
        try
        {
            if(c[i]!='1' && c[i]!='0')
                throw c[i];
        }
        catch(char a)
        {
            cout<<a<<" is not binary"<<endl;
        }
        if(c[i]=='1')
            s.push(1);
        else
            s.push(0);
    }
    return s;
}
stack<int> add(stack<int> &z1,stack<int> &z2)
{
    stack<int> x;
    int b1,b2,sum=0,carry=0;
    while(!z1.empty() || !z2.empty())
    {
        b1=0;
        b2=0;
        if(!z1.empty())
        {
            b1=z1.top();
            z1.pop();
        }
        if(!z2.empty())
        {
            b2=z2.top();
            z2.pop();
        }
        sum=(b1+b2+carry)%2;
        carry=(b1+b2+carry)/2;
        x.push(sum);
    }
    if(carry==1)
        x.push(1);
    return x;

}

int main()
{
    stack<int>s1,s2,s3;
    s1=read();
    s2=read();
    s3=add(s1,s2);
    display(s3);
    return 0;
}
