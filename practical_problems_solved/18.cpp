#include<iostream>
#include<set>
#include<string.h>
#include<iomanip>
using namespace std;
class person
{
    public:
    string name,dob;
    long phn;
    person(string n,string d,long p)
    {
        name=n;
        dob=d;
        phn=p;
    }
    bool operator<(const person &b)const
    {
        return name<b.name;
    }
};
int main()
{
    int ch,flag;
    string na,da;
    long ph;
    set<person>data;
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
        case 1: cout<<"\n\t***enter person details***";
                cout<<"\nEnter name:";
                cin>>na;
                cout<<"\nEnter date of birth(dd/mm/yyyy)";
                cin>>da;
                cout<<"\nEnter phone no(up to 8 digits)";
                cin>>ph;
                data.insert(person(na,da,ph));
            break;
        case 2: cout<<"Enter the name to search:";
                cin>>na;
                flag=0;
                for(set<person>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->name==na)
                    {
                        cout<<endl<<"FOUND\n"<<it->name<<" "<<it->dob<<" "<<it->phn<<endl;
                        flag=1;
                    }
                }
                if(flag==0)
                    cout<<endl<<"NOT FOUND\n";
            break;
        case 3: cout<<"Enter the DOB(dd/mm/yyyy) to search: ";
                cin>>da;
                flag=0;
                for(set<person>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->dob==da)
                    {
                        cout<<endl<<"FOUND\n"<<it->name<<" "<<it->dob<<" "<<it->phn<<endl;
                        flag=1;
                    }
                }
                if(flag==0)
                    cout<<endl<<"NOT FOUND\n";
            break;
        case 4: cout<<"Enter the phone no. to search: ";
                cin>>ph;
                flag=0;
                for(set<person>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->phn==ph)
                    {
                        cout<<endl<<"FOUND\n"<<it->name<<" "<<it->dob<<" "<<it->phn<<endl;
                        flag=1;
                    }
                }
                if(flag==0)
                    cout<<endl<<"NOT FOUND\n";
            break;
        case 5: cout<<"\t"<<left<<setw(15)<<"NAME"<<left<<setw(15)<<"DATE OF BIRTH"<<left<<setw(15)<<"PHONE NO\n";
                for(set<person>::iterator it=data.begin();it!=data.end();it++)
                    cout<<"\t"<<left<<setw(15)<<it->name<<left<<setw(15)<<it->dob<<left<<setw(15)<<it->phn<<endl;
            break;
        case 6:
            return 77;
        default:
            cout<<endl<<"INVALID INPUT\n";
        }
    }
    return 0;
}
