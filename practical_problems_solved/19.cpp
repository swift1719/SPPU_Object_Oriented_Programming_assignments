#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
class item
{
public:
    string name;
    long code;
    int cost;
    item(string na,long cd,int cs)
    {
        name=na;
        code=cd;
        cost=cs;
    }
    bool operator<(const item &b)const
    {
        return name<b.name;
    }
};
main()
{
    int ch,cst,flag=0;
    long bar;
    string na;
    set<item>data;
    cout<<endl<<"***BILL***\n";
    for(;;)
    {
        cout<<"PRESS:\n1.to Insert & Sort Item\n2.to Search Person By Item Name\n3.to Search Person By Item code\n4.to Search Person By Item Cost\n5.to Display All Items\n6.to EXIT\n";
        cin>>ch;
        switch(ch)
        {
        case 1: cout<<endl<<"Enter name: ";
                cin>>na;
                cout<<"Enter item code: ";
                cin>>bar;
                cout<<"Enter item cost: ";
                cin>>cst;
                cout<<endl;
                data.insert(item(na,bar,cst));
            break;
        case 2: cout<<endl<<"Enter a item name to search: ";
                cin>>na;
                flag=0;
                for(set<item>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->name==na)
                    {
                        cout<<endl<<left<<setw(15)<<it->name<<left<<setw(15)<<it->code<<left<<setw(15)<<it->cost<<endl;
                        flag=1;
                    }
                }
                if(flag==0)
                    cout<<endl<<"\tNOT FOUND"<<endl;
            break;
        case 3: cout<<endl<<"Enter a item code to search: ";
                cin>>bar;
                flag=0;
                for(set<item>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->code==bar)
                    {
                        cout<<endl<<left<<setw(15)<<it->name<<left<<setw(15)<<it->code<<left<<setw(15)<<it->cost<<endl;
                        flag=1;
                    }
                }
                if(flag==0)
                    cout<<endl<<"\tNOT FOUND"<<endl;
            break;
        case 4: cout<<endl<<"Enter a item code to search: ";
                cin>>cst;
                flag=0;
                for(set<item>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->cost==cst)
                    {
                        cout<<endl<<left<<setw(15)<<it->name<<left<<setw(15)<<it->code<<left<<setw(15)<<it->cost<<endl;
                        flag=1;
                    }
                }
                if(flag==0)
                    cout<<endl<<"\tNOT FOUND"<<endl;
            break;
        case 5: cout<<endl<<"\t"<<left<<setw(15)<<"NAME"<<left<<setw(15)<<"CODE"<<left<<setw(15)<<"COST"<<endl;
                for(set<item>::iterator it=data.begin();it!=data.end();it++)
                {
                    cout<<"\t"<<left<<setw(15)<<it->name<<left<<setw(15)<<it->code<<left<<setw(15)<<it->cost<<endl;
                }
            break;
        case 6:
            return 17;
        default:
            cout<<endl<<"INVALID INPUT"<<endl;
        }
    }
    return 0;
}
