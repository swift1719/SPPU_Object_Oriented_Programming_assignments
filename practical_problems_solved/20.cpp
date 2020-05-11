#include<iostream>
#include<set>
#include<iomanip>
#include<string>
using namespace std;
class election
{
public:
    string name,vote;
    int id,age;
    election(string n,string vo,int i,int ag)
    {
        name=n;
        vote=vo;
        id=i;
        age=ag;
    }
    bool operator<(const election &b)const
    {
        return id<b.id;
    }
};
main()
{
    string na,v;
    int ch,idd,vag,nda,flag,inc,sp;
    set<election>data;
    cout<<endl<<"\t***ELECTION***\n";
    for(;;)
    {
        cout<<endl<<"PRESS:\n1.to vote\n2.to display voters list\n3.to display result\n4.to EXIT\n";
        cin>>ch;
        switch(ch)
        {
        case 1: cout<<"Enter name: ";
                cin>>na;
                cout<<"Enter age: ";
                cin>>vag;
                flag=0;
                if(vag<18)
                {
                    cout<<"\nNOT ELIGIBLE TO VOTE\n";
                    break;
                }
                cout<<"Enter voter id: ";
                cin>>idd;
                cout<<"Enter vote: \nTYPE one name amongst the following:\nNDA\nINC\nSP\n";
                cin>>v;
                if(v=="NDA" || v=="INC" || v=="SP")
                    flag=1;
                if(flag==1)
                    data.insert(election(na,v,idd,vag));
                else
                    cout<<"\nINVALID SELECTION OF VOTE\n";
            break;
        case 2: cout<<endl<<left<<setw(15)<<"NAME"<<left<<setw(10)<<"Voter ID"<<left<<setw(10)<<"AGE\n";
                for(set<election> ::iterator it=data.begin();it!=data.end();it++)
                {
                    cout<<endl<<left<<setw(15)<<it->name<<left<<setw(10)<<it->id<<left<<setw(10)<<it->age;
                }
                cout<<endl;
            break;
        case 3: nda=inc=sp=0;
                cout<<endl<<"\t"<<left<<setw(15)<<"NDA"<<left<<setw(10)<<"INC"<<left<<setw(10)<<"SP";
                for(set<election> ::iterator it=data.begin();it!=data.end();it++)
                {
                    if(it->vote=="NDA")
                        nda++;
                    if(it->vote=="INC")
                        inc++;
                    if(it->vote=="SP")
                        sp++;
                }
                cout<<endl<<"\t"<<left<<setw(15)<<nda<<left<<setw(10)<<inc<<left<<setw(10)<<sp;
                if(nda>inc && nda>sp)
                    cout<<endl<<"\tNDA won election\n";
                else if(inc>nda && inc>sp)
                    cout<<endl<<"\tINC won election\n";
                else if(sp>nda && sp>inc)
                    cout<<endl<<"\tSP won the election\n";
                else
                    cout<<endl<<"\tNO PARTY WINS\n";
            break;
        case 4:
            return 77;
        default:
            cout<<endl<<"\tINVALID INPUT\n";
        }
    }
    return 0;
}
