#include<iostream>
#include<set>
#include<string>
#include<iomanip>
using namespace std;
class hotel
{
public:
    int items[5],table;
     string name;
     float amt;
     hotel(string na,int a[],int t,float am)
     {
         name=na;
         table=t;
         items[0]=a[0];
         items[1]=a[1];
         items[2]=a[2];
         items[3]=a[3];
         items[4]=a[4];
         amt=am;
     }
     bool operator<(const hotel &b)const
     {
         return table<b.table;
     }
};
int main()
{
    set<hotel>data;
    string na;
    float am;
    int a[5]={0};
    int t,ch,flag,cnt;
    cout<<endl<<"***HOTEL***\n";
    for(;;)
    {
        cout<<endl<<"PRESS:\n1.to Place New Order\n2.to Display All Orders\n3.to Search By Table Number\n4.to Search By Customer Name\n5.to EXIT\n";
        cin>>ch;
        switch(ch)
        {
        case 1: cout<<"Enter name: ";
                cin.ignore();
                getline(cin,na);
                cout<<"Enter table no.: ";
                cin>>t;
                cout<<"\n\t***MENU***\n";
                cout<<left<<setw(15)<<"ITEMS"<<left<<setw(10)<<"COST"<<endl;
                cout<<left<<setw(15)<<"NOODLES"<<left<<setw(10)<<"65.00/-"<<endl;
                cout<<left<<setw(15)<<"PEPSI"<<left<<setw(10)<<"45.00/-"<<endl;
                cout<<left<<setw(15)<<"TEA"<<left<<setw(10)<<"15.00/-"<<endl;
                cout<<left<<setw(15)<<"COFFEE"<<left<<setw(10)<<"20.00/-"<<endl;
                cout<<left<<setw(15)<<"PIZZA"<<left<<setw(10)<<"79.00/-"<<endl;
                cout<<"Enter no. of NOODLES: ";
                cin>>a[0];
                cout<<"Enter no. of PEPSI: ";
                cin>>a[1];
                cout<<"Enter no. of TEA: ";
                cin>>a[2];
                cout<<"Enter no. of COFFEE: ";
                cin>>a[3];
                cout<<"Enter no. of PIZZA: ";
                cin>>a[4];
                am=(a[0]*65)+(a[1]*45)+(a[2]*15)+(a[3]*20)+(a[4]*79);
                data.insert(hotel(na,a,t,am));
            break;
        case 2:
                cnt=0;
                cout<<"ALL ORDER DETAILS\n";
                for(set<hotel>::iterator it=data.begin();it!=data.end();it++)
                {
                    cout<<"\nTABLE NO: "<<it->table<<endl;
                    cout<<"\nCUSTOMER NAME: "<<it->name<<endl;
                    cout<<left<<setw(15)<<"ITEMS"<<left<<setw(10)<<"QUANTITY"<<left<<setw(10)<<"COST"<<endl;
                    cout<<left<<setw(15)<<"NOODLES"<<left<<setw(10)<<it->items[0]<<left<<setw(10)<<it->items[0]*65.00<<endl;
                    cout<<left<<setw(15)<<"PEPSI"<<left<<setw(10)<<it->items[1]<<left<<setw(10)<<it->items[1]*45.00<<endl;
                    cout<<left<<setw(15)<<"TEA"<<left<<setw(10)<<it->items[2]<<left<<setw(10)<<it->items[2]*15.00<<endl;
                    cout<<left<<setw(15)<<"COFFEE"<<left<<setw(10)<<it->items[3]<<left<<setw(10)<<it->items[3]*20.00<<endl;
                    cout<<left<<setw(15)<<"PIZZA"<<left<<setw(10)<<it->items[4]<<left<<setw(10)<<it->items[4]*79.00<<endl;
                    cout<<setw(30)<<"ORDER TOTAL: "<<setiosflags(ios::fixed)<<setprecision(2)<<it->amt<<"/-"<<endl;
                    cnt++;
                }
                if(cnt==0)
                    cout<<"\nNO ORDER FOUND\n";
            break;
        case 3: cout<<endl<<"Enter table no.: ";
                cin>>t;
                flag=0;
                cout<<"ORDER DETAILS: \n";
                for(set<hotel>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->table==t)
                    {
                    cout<<"\nCUSTOMER NAME: "<<it->name<<endl;
                    cout<<left<<setw(15)<<"ITEMS"<<left<<setw(10)<<"QUANTITY"<<left<<setw(10)<<"COST"<<endl;
                    cout<<left<<setw(15)<<"NOODLES"<<left<<setw(10)<<it->items[0]<<left<<setw(10)<<it->items[0]*65.00<<endl;
                    cout<<left<<setw(15)<<"PEPSI"<<left<<setw(10)<<it->items[1]<<left<<setw(10)<<it->items[1]*45.00<<endl;
                    cout<<left<<setw(15)<<"TEA"<<left<<setw(10)<<it->items[2]<<left<<setw(10)<<it->items[2]*15.00<<endl;
                    cout<<left<<setw(15)<<"COFFEE"<<left<<setw(10)<<it->items[3]<<left<<setw(10)<<it->items[3]*20.00<<endl;
                    cout<<left<<setw(15)<<"PIZZA"<<left<<setw(10)<<it->items[4]<<left<<setw(10)<<it->items[4]*79.00<<endl;
                    flag=1;
                    cout<<setw(30)<<"ORDER TOTAL: "<<setiosflags(ios::fixed)<<setprecision(2)<<it->amt<<"/-"<<endl;
                    }
                }
                if(flag==0)
                    cout<<"\nNO ORDER FOUND\n";
            break;
        case 4: cout<<endl<<"Enter customer no.: ";
                cin.ignore();
                getline(cin,na);
                flag=0;
                cout<<"ORDER DETAILS: ";
                for(set<hotel>::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->name==na)
                    {
                    cout<<"\nTABLE NO: "<<it->table<<endl;
                    cout<<left<<setw(15)<<"ITEMS"<<left<<setw(10)<<"QUANTITY"<<left<<setw(10)<<"COST"<<endl;
                    cout<<left<<setw(15)<<"NOODLES"<<left<<setw(10)<<it->items[0]<<left<<setw(10)<<it->items[0]*65.00<<endl;
                    cout<<left<<setw(15)<<"PEPSI"<<left<<setw(10)<<it->items[1]<<left<<setw(10)<<it->items[1]*45.00<<endl;
                    cout<<left<<setw(15)<<"TEA"<<left<<setw(10)<<it->items[2]<<left<<setw(10)<<it->items[2]*15.00<<endl;
                    cout<<left<<setw(15)<<"COFFEE"<<left<<setw(10)<<it->items[3]<<left<<setw(10)<<it->items[3]*20.00<<endl;
                    cout<<left<<setw(15)<<"PIZZA"<<left<<setw(10)<<it->items[4]<<left<<setw(10)<<it->items[4]*79.00<<endl;
                    flag=1;
                    cout<<setw(30)<<"ORDER TOTAL: "<<setiosflags(ios::fixed)<<setprecision(2)<<it->amt<<"/-"<<endl;
                    }
                }
                if(flag==0)
                    cout<<"\nNO ORDER FOUND\n";
            break;
        case 5:
            return 17;
        default:
            cout<<endl<<"INVALID INPUT\n";
        }
    }

    return 0;
}
