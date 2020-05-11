#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class comp
{
    float real,img;
public:
    comp()
    {
        real=0;
        img=0;
    }
    friend istream & operator>>(istream &in,comp &obj);
    friend ostream & operator<<(ostream &out,const comp &obj);
    comp operator+(comp obj);
    comp operator-(comp obj);
    comp operator*(comp obj);
    comp operator/(comp obj);
};
istream & operator>>(istream &in,comp &obj)
{
    cout<<endl<<"ENTER COMPLEX NO.: ";
    in>>obj.real;
    cout<<" + i ";
    in>>obj.img;
    return in;
}
ostream & operator<<(ostream &out,const comp &obj)
{
    out<<endl<<"RESULTANT COMPLEX NO.: (";
    out<<obj.real<<") + i ("<<obj.img<<")"<<endl;
    return out;
}
comp comp::operator+(comp obj)
{
    comp temp;
    temp.real=real+obj.real;
    temp.img=img+obj.img;
    return temp;
}
comp comp::operator-(comp obj)
{
    comp temp;
    temp.real=real-obj.real;
    temp.img=img-obj.img;
    return temp;
}
comp comp::operator*(comp obj)
{
    comp temp;
    temp.real=(real*obj.real)-(img*obj.img);
    temp.img=(real*obj.img)+(img*obj.real);
    return temp;
}
comp comp::operator/(comp obj)
{
    comp temp;
    temp.real= ((real*obj.real) - (img*obj.img)) / ((pow(obj.real,2)) + (pow(obj.img,2)));
    temp.img = ((img*obj.real) - (real*obj.img)) /  ((pow(obj.real,2)) + (pow(obj.img,2)));
    return temp;
}

int main()
{
    int ch;
    comp c,c1,result;
    cout<<endl<<"Complex Numbers"<<endl;

    for(;;)
    {
        cout<<endl<<"PRESS:\n1.to add\n2.to subtract\n3.to multiply\n4.to divide\n5.to EXIT"<<endl;
        cin>>ch;
    switch(ch)
    {
    case 1: cin>>c;
            cin>>c1;
            result=c+c1;
            cout<<result;
        break;
    case 2: cin>>c;
            cin>>c1;
            result=c-c1;
            cout<<result;
        break;
    case 3: cin>>c;
            cin>>c1;
            result=c*c1;
            cout<<result;
        break;
    case 4: cin>>c;
            cin>>c1;
            result=c/c1;
            cout<<result;
        break;
    case 5:
        exit(0);
    default:
        cout<<endl<<"INVALID INPUT"<<endl;
    }
    }
    return 0;
}
