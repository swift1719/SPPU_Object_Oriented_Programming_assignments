#include<iostream>
#include<stdlib.h>
using namespace std;
class rat
{
    double p,q;
public:
    friend istream & operator>>(istream &in,rat &obj);
    friend ostream & operator<<(ostream &out,const rat &obj);
    rat operator+(rat obj);
    rat operator-(rat obj);
    rat operator*(rat obj);
    rat operator/(rat obj);
    bool operator>(rat obj);
    bool operator<(rat obj);
    bool operator>=(rat obj);
    bool operator<=(rat obj);
    bool operator==(rat obj);
    bool operator!=(rat obj);
};
istream &operator>>(istream &in,rat &obj)
{
    label:
    cout<<endl<<"Enter the no.(p/q):";
    in>>obj.p>>obj.q;
    if(obj.q==0)
    {
        cout<<endl<<"INVALID INPUT as denominator of rational no. can't be zero."<<endl;
        goto label;
    }
    return in;
}
ostream & operator<<(ostream &out,const rat &obj)
{
    cout<<endl<<"THE RATIONAL no. is: ";
    out<<"("<<obj.p<<"/"<<obj.q<<")"<<endl;
    return out;
}
rat rat::operator+(rat obj)
{
    rat temp;
    temp.p=(p*obj.q)+(q*obj.p);
    temp.q=(q*obj.q);
    return temp;
}
rat rat::operator-(rat obj)
{
    rat temp;
    temp.p=(p*obj.q)-(q*obj.p);
    temp.q=(q*obj.q);
    return temp;
}
rat rat::operator/(rat obj)
{
    rat temp;
    temp.p=(p*obj.q);
    temp.q=(q*obj.p);
    return temp;
}
rat rat::operator*(rat obj)
{
    rat temp;
    temp.p=(p*obj.p);
    temp.q=(q*obj.q);
    return temp;
}
bool rat::operator>(rat obj)
{
    float f1,f2;
    f1=p/q;
    f2=(obj.p/obj.q);
    if(f1>f2)
        return true;
    return false;
}
bool rat::operator<(rat obj)
{
    float f1,f2;
    f1=p/q;
    f2=(obj.p/obj.q);
    if(f1<f2)
        return true;
    return false;
}
bool rat::operator>=(rat obj)
{
    float f1,f2;
    f1=p/q;
    f2=(obj.p/obj.q);
    if(f1>=f2)
        return true;
    return false;
}
bool rat::operator<=(rat obj)
{
    float f1,f2;
    f1=p/q;
    f2=(obj.p/obj.q);
    if(f1<=f2)
        return true;
    return false;
}
bool rat::operator==(rat obj)
{
    float f1,f2;
    f1=p/q;
    f2=(obj.p/obj.q);
    if(f1==f2)
        return true;
    return false;
}
bool rat::operator!=(rat obj)
{
    float f1,f2;
    f1=p/q;
    f2=(obj.p/obj.q);
    if(f1!=f2)
        return true;
    return false;
}

int main()
{
    rat r1,r2,r3;
    int ch;
    cin>>r1;
    cout<<r1;
    cin>>r2;
    cout<<r2;
    for(;;)
    {
        cout<<endl<<"PRESS:\n1.to add\n2.to subtract\n3.to multiply\n4.to divide\n5. greater than\n6. less than\n7.greater than equal to\n8. less than equal to\n9.equal to\n10.not equal\n11.to exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
                r3=r1+r2;
                cout<<endl<<"Resultant->";
                cout<<r3;
            break;
        case 2:
                r3=r1-r2;
                cout<<endl<<"Resultant->";
                cout<<r3;
            break;
        case 3:
                r3=r1*r2;
                cout<<endl<<"Resultant->";
                cout<<r3;
            break;
        case 4:
                r3=r1/r2;
                cout<<endl<<"Resultant->";
                cout<<r3;
            break;
        case 5: if(r1>r2)
                {
                    cout<<endl<<"YES. R1>R2"<<endl;
                    break;
                }
                cout<<endl<<"FALSE"<<endl;
            break;
        case 6: if(r1<r2)
                {
                    cout<<endl<<"YES. R1<R2"<<endl;
                    break;
                }
                cout<<endl<<"FALSE"<<endl;
            break;
        case 7: if(r1>=r2)
                {
                    cout<<endl<<"YES. R1>=R2"<<endl;
                    break;
                }
                cout<<endl<<"FALSE"<<endl;
            break;
        case 8: if(r1<=r2)
                {
                    cout<<endl<<"YES. R1<=R2"<<endl;
                    break;
                }
                cout<<endl<<"FALSE"<<endl;
            break;
        case 9: if(r1==r2)
                {
                    cout<<endl<<"YES. R1==R2"<<endl;
                    break;
                }
                cout<<endl<<"FALSE"<<endl;
            break;
        case 10:if(r1!=r2)
                {
                    cout<<endl<<"YES. R1!=R2"<<endl;
                    break;
                }
                cout<<endl<<"FALSE"<<endl;
            break;
        case 11:
            exit(0);
        default:
            cout<<endl<<"INVLAID INPUT"<<endl;
        }
    }
    return 0;
}
