#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
class person
{public:
    string name,bod;
    long phno;
    person(string n,string b,long p): name(n),bod(b),phno(p){};
    bool operator<(const person &b) const
    {
        return name<b.name;
    }
};
int main()
{
    int ch;
    string na;
    string b;
    long p;
    set<person>data;
    cout<<"\n\t***RECORD***\n";
    for(;;)
    {
        cout<<"\nPRESS:\n";
        cout<<"\n1.to insert and sort person";
        cout<<"\n2.to search person by name";
        cout<<"\n3.to search person by date of birth";
        cout<<"\n4.to search person by phone no";
        cout<<"\n5.to display all person";
        cout<<"\n6.to exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n\t enter person:";
                    cout<<"\n\t enter name:";
                    cin>>na;
                    cout<<"\n enter date of birth(dd\mm\yy)";
                    cin>>b;
                    cout<<"\n enter phone no(upto 8 digits)";
                    cin>>p;
                    data.insert(person(na,b,p));
                    break;
            case 2: cout<<"enter the name to search:";
                    cin>>na;
                    for(std::set<person>::const_iterator it=data.begin();it!=data.end();it++)
                    {
                        if(it->name==na)
                            cout<<it->name<<","<<it->bod<<","<<it->phno;
                        else
                            continue;
                    }
                    break;

            case 3: cout<<"enter the date of birth to search:";
                    cin>>b;
                    for(std::set<person>::const_iterator it=data.begin();it!=data.end();it++)
                    {
                        if(it->bod==b)
                            cout<<it->name<<","<<it->bod<<","<<it->phno;
                        else
                            continue;
                   }
                   break;
            case 4: cout<<"enter the phone no to search:";
                    cin>>p;
                    for(std::set<person>::const_iterator it=data.begin();it!=data.end();it++)
                    {
                        if(it->phno==p)
                            cout<<it->name<<","<<it->bod<<","<<it->phno;
                        else
                            continue;
                    }
                   break;
            case 5: cout<<"\t"<<left<<setw(15)<<"NAME"<<left<<setw(15)<<"DATE OF BIRTH"<<left<<setw(15)<<"PHONE NO\n";
                    for(std::set<person>::const_iterator it=data.begin();it!=data.end();it++)
                        cout<<"\t"<<left<<setw(15)<<it->name<<left<<setw(15)<<it->bod<<left<<setw(15)<<it->phno;
                    break;
            case 6: return 0;
            default:cout<<"wrong choice";
                    break;
            }
    }
        return 0;
};
