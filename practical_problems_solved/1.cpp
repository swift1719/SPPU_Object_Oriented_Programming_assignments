#include<iostream>
#include<stdlib.h>
using namespace std;
class cal
{
    float a;
public:
    void ip();
    float operator+(cal);
    float operator-(cal);
    float operator*(cal);
    float operator/(cal);
    void operator%(cal);
};
void cal::ip()
{
    cout<<endl<<"ENTER VALUE: ";
    cin>>a;
}
float cal::operator+(cal obj)
{
    float val;
    val=a+obj.a;
    return val;
}
float cal::operator-(cal obj)
{
    float val;
    val=a-obj.a;
    return val;
}
float cal::operator*(cal obj)
{
    float val;
    val=a*obj.a;
    return val;
}
float cal::operator/(cal obj)
{
    float val;
    val=a/obj.a;
    return val;
}
void cal::operator%(cal obj)
{
    int val;
    val=(int)a%(int)obj.a;
    cout<<endl<<"REMAINDER IN DIVISION IS: "<<val<<endl;
}
int main()
{
    cal c,c1;
    int ch;
    cout<<endl<<"CALCULATOR"<<endl;
    for(;;)
    {
        cout<<endl<<"PRESS:\n1.to add\n2.to subtract\n3.to multiply\n4.to divide\n5.to get remainder \n6.to EXIT."<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1: c.ip();
                c1.ip();
                cout<<endl<<"SUM IS: "<<c+c1<<endl;
            break;
        case 2: c.ip();
                c1.ip();
                cout<<endl<<"DIFFERENCE IS: "<<c-c1<<endl;
            break;
        case 3: c.ip();
                c1.ip();
                cout<<endl<<"MULTIPLICATION IS: "<<c*c1<<endl;
            break;
        case 4: c.ip();
                c1.ip();
                cout<<endl<<"DIVISION IS: "<<c/c1<<endl;
            break;
        case 5: c.ip();
                c1.ip();
                c%c1;
        case 6: exit(0);
        default:cout<<"INVALID INPUT";
            break;
        }
    }
    return 0;
}
