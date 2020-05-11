#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class invent
{
    char name[10];
    int code;
    float cost;
public:
    void readdata();
    void writedata();

};
void invent::readdata()
{
    cout<<endl<<"ENTER NAME : ";
    cin>>name;
    cout<<endl<<"ENTER CODE : ";
    cin>>code;
    cout<<endl<<"ENTER COST: ";
    cin>>cost;
}
void invent::writedata()
{
    cout<<setw(10)<<name<<setiosflags(ios::right)<<setw(10)<<code<<setprecision(2)<<setiosflags(ios::fixed)<<setw(10)<<cost<<endl;
}
main()
{
    invent item[3];
    fstream file;
    file.open("stock.dat",ios::in | ios::out);
    cout<<endl<<"Enter details for three items \n";
    for(int i=0;i<3;i++)
    {
        item[i].readdata();
        file.write((char *)&item[i],sizeof(item[i]));
    }
    file.seekg(0);
    cout<<endl<<"OUTPUT\n";
    for(int i=0;i<3;i++)
    {
        file.read((char *)&item[i],sizeof(item[i]));
        item[i].writedata();
    }
    file.close();

    return 0;
}
