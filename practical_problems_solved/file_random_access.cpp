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
    void getdata()
    {
        cout<<endl<<"Enter a name: ";
        cin>>name;
        cout<<"Enter code: ";
        cin>>code;
        cout<<endl<<"Enter cost: ";
        cin>>cost;
    }
    void putdata()
    {
        cout<<setw(10)<<name<<setw(10)<<code<<setprecision(2)<<setw(10)<<cost<<endl;
    }
};
int main()
{
    invent item;
    fstream file;
    file.open("stock.dat",ios::ate | ios::in | ios::out | ios::binary);
    file.seekg(0,ios::beg);
    cout<<endl<<"CURRENT CONTENTS \n";
    while(file.read((char *)&item,sizeof(item)))
    {
        item.putdata();
    }
    file.clear();
    cout<<"\nADD AN ITEM\n";
    item.getdata();
    char ch;
    file.write((char *)&item,sizeof(item));
    file.seekg(0);
    cout<<endl<<"\nCONTENTS OF APPENDED FILE\n";
    while(file.read((char *)&item,sizeof(item)))
    {
        item.putdata();
    }
    int last=file.tellg();
    int n=last/sizeof(item);
    cout<<endl<<"NO. of objects: "<<n<<endl;
    cout<<"FILE SIZE: "<<last<<endl;
    cout<<"MODIFY DETAILS OF AN ITEM"<<endl;

    cout<<"Enter object no. to be updated\n";
    int object;
    cin>>object;
    cin.get(ch);
    int location= (object -1) * sizeof(item);
    if(file.eof())
    {
        file.clear();
    }
    file.seekp(location);
    cout<<"Enter new values of the object \n";
    item.getdata();
    cin.get(ch);
    file.write((char *)&item,sizeof(item))<<flush;
    file.seekg(0);
    cout<<endl<<"CONTENTS OF UPDATED FILE\n";
    while(file.read((char *)&item,sizeof(item)))
    {
        item.putdata();
    }
    file.close();
    return 0;
}
