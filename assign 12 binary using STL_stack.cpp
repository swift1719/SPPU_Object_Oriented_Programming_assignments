#include<bits/stdc++.h>
using namespace std;
stack<int>read();
void display(stack<int> &s);
stack<int>add(stack<int> &s1,stack<int>&s2);
int main()
{
    stack<int> s1,s2,s3;
    s1=read();
    s2=read();
    s3=add(s1,s2);
    display(s3);
    return 0;
}
stack<int> read()
{ char a[40];
stack<int>s;
 cout<<"\nENTER A BINARY NUMBER:\n";
 cin>>a;
 for(int i=0;a[i]!='\0';i++)
 {   try
   { if(a[i]!='0'&&a[i]!='1')
         throw a[i];
  }
 catch(char a)
 {
    cout<<a<<" is not a binary number\n";
 }





     if(a[i]=='1')
            s.push(1);
      else
        s.push(0);
 }
  return s;
}
stack<int>add(stack<int>&s1,stack <int> &s2)
{
    stack<int>s;
    int sum,carry=0;
    int b1,b2;
    while(!s1.empty()||!s2.empty())
    {  b1=b2=0;
    if(!s1.empty())
    {
        b1=s1.top();
        s1.pop();
    }
    if(!s2.empty())
    {
        b2=s2.top();
        s2.pop();
    }
    sum=(b1+b2+carry)%2;
    carry=(b1+b2+carry)/2;
    s.push(sum);
    }
    if(carry==1)
      s.push(1);
      return s;
}
void display(stack <int> &s)
{
    cout<<"\nSUM:\n";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }

}
