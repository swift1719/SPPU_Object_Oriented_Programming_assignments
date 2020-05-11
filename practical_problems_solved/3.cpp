#include<iostream>
#include<math.h>
using namespace std;
class quad
{
    float a,b,c,x;
public:

    friend istream & operator>>(istream &in,quad &obj);
    friend ostream & operator<<(ostream &out,const quad &obj);
    quad operator +(quad obj);
    void eval();
    void findroots();
};

istream & operator >>(istream &in,quad &obj)
{
    cout<<endl<<"ENTER values of a,b,c: ";
    in>>obj.a>>obj.b>>obj.c;
    return in;
}
ostream & operator <<(ostream &out ,const quad &obj)
{
    out<<endl<<"Quadratic equation is: ";
    out<<obj.a<<"*x*x + "<<obj.b<<"*x + "<<obj.c<<" "<<endl;
    return out;
}
quad quad::operator+(quad obj)
{
    quad t;
    t.a=(a+obj.a);
    t.b=(b+obj.b);
    t.c=(c+obj.c);
    return t;
}
void quad::eval()
{
    cout<<"ENTER VALUE OF x:";
    cin>>x;
    cout<<endl<<"EVALUATED VALUE OF EXPRESSION FOR "<<x<<" is: "<<((a*x*x) + (b*x) + c)<<endl;
}
void quad:: findroots()
{
    double temp,root2,root1;
    temp= (b*b)-(4*a*c);
    if(temp>0)
    {
        cout<<endl<<"ROOTS ARE REAL AND DISTINCT"<<endl;
        root1=((-b)+(sqrt(temp))) / (2*a);
        root2=((-b)-(sqrt(temp))) / (2*a);
    }
    else if(temp==0)
    {
        cout<<endl<<"ROOTS ARE EQUAL"<<endl;
        root2=((-b)-(sqrt(temp))) / (2*a);
    }
    else
    {
        cout<<endl<<"ROOTS ARE COMPLEX"<<endl;
        int w;
        w=(-b)/(2*a);
        root2= sqrt(-temp)/(2*a);
        cout<<endl<<"ROOT 1 : ("<<w<<") + i ("<<root2<<")"<<endl;
        cout<<endl<<"ROOT 2 : ("<<w<<") - i ("<<root2<<")"<<endl;
        return ;
    }
    cout<<endl<<"ROOTS ARE : ("<<root1<<") and ("<<root2<<")"<<endl;
}
int main()
{
quad q1,q2,q3;

cin>>q1;
q1.eval();
q1.findroots();
cout<<endl<<"***********************************"<<endl;
cin>>q2;
cout<<q2;
q2.eval();
q2.findroots();
cout<<endl<<"***********************************"<<endl;
q3= q1 + q2;
q3.eval();
q3.findroots();
return 0;
}
