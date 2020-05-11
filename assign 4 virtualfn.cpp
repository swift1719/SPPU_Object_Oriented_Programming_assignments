#include<iostream>
#include<stdlib.h>
using namespace std;
class unit
{
protected:
    double val1,val2;
public:
    void ip();
    double original();
    double converted();
    virtual void convert()=0;
};
void unit::ip()
{
    cout<<"ENTER VALUE TO BE CONVERTED: ";
    cin>>val1;
    val2=val1;
}
double unit::original()
{
    return val1;
}
double unit::converted()
{
    return val2;
}

class mtokm:public unit
{
public:
    void convert()
    {
        val2=val1/1000;
    }
};
class cmtoinch:public unit
{
public:
    void convert()
    {
        val2=val1/2.54;
    }
};
class inchtofoot:public unit
{
public:
    void convert()
    {
        val2=val1/12;
    }
};
int main()
{
mtokm p;
cmtoinch q;
inchtofoot r;
int ch;
cout<<endl<<"\tCONVERSIONS"<<endl;
for(;;)
{
    cout<<endl<<"PRESS:\n1.for metre to kms\n2.for cms to inch\n3.for inch to foot\n4.to exit"<<endl;
    cin>>ch;
    switch(ch)
    {
    case 1: p.ip();
            p.original();
            p.convert();
            cout<<"CONVERTED VALUE:"<<p.converted()<<endl;
        break;
    case 2: q.ip();
            q.original();
            q.convert();
            cout<<"CONVERTED VALUE:"<<q.converted()<<endl;
        break;
    case 3: r.ip();
            r.original();
            r.convert();
            cout<<"CONVERTED VALUE:"<<r.converted()<<endl;
        break;
    case 4:
        exit(0);
    default:
        cout<<endl<<"INVALID INPUT"<<endl;
    }
}
return 0;
}
