 #include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;
class telephone
{
    char na[20],tel[15];
public:
    void getdata()
    {
        cout<<endl<<"Enter name: ";
        cin>>na;
        cout<<endl<<"Enter telephone no. : ";
        cin>>tel;
    }
    void putdata()
    {
        cout<<setiosflags(ios::left)<<setw(20)<<na<<setw(15)<<tel<<endl;
    }
    char *getname()
    {
        return na;
    }
    char *gettel()
    {
        return tel;
    }
    void update(char *name,char *tele)
    {
        strcpy(na,name);
        strcpy(tel,tele);
    }
};
main()
{
    char ch,telno[15],nam[20];
    int choice,flag=0,cnt;
    fstream f;
    telephone t;
    f.open("phonebook.txt",ios::in | ios::out);
    cout<<"\n\tTelephone Directory\n";
    for(;;)
    {
        cout<<"\nPRESS:\n1.to Create Record\n2.to Display All Records\n3.to Search by Name\n4.to Search by Telephone Number\n5.to Update Telephone Number\n6.to Exit\n";
		cin>>choice;
		switch(choice)
		{
		    case 1: t.getdata();
                    f.write((char *)&t,sizeof(t));
                    break;
            case 2: cout<<endl<<"\t TELEPHONE NUMBERS "<<endl;
                    cout<<setiosflags(ios::left)<<setw(20)<<"NAME"<<setw(20)<<"Phone no."<<endl;
                    f.seekg(0,ios::beg);
                    while(f.read((char *)&t,sizeof(t)))
                    {
                        t.putdata();
                    }
                    f.clear();
                    break;
            case 3: cout<<endl<<"Enter a name to search : ";
                    cin>>nam;
                    flag=0;
                    f.seekg(0,ios::beg);
                    while(f.read((char *)&t,sizeof(t)))
                    {
                        if(strcmp(t.getname(),nam)==0)
                        {
                            flag=1;
                            cout<<"\n  Name \t\tTelephoneNumber\n";
                            t.putdata();
                            break;
                        }
                    }
                    f.clear();
                    if(flag==0)
                    {
                        cout<<endl<<"Record not found"<<endl;
                    }
                    break;
            case 4: cout<<endl<<"Enter a phone number to search : ";
                    cin>>telno;
                    flag=0;
                    f.seekg(0,ios::beg);
                    while(f.read((char *)&t,sizeof(t)))
                    {

                        if(strcmp(t.gettel(),telno)==0)
                        {
                            flag=1;
                            cout<<"\n  Name \t\tTelephoneNumber\n";
                            t.putdata();
                            break;
                        }
                    }
                    f.clear();
                    if(flag==0)
                    {
                        cout<<endl<<"Record not found"<<endl;
                    }
                    break;
            case 5: cout<<endl<<"Enter a name for updating no. : ";
                    cin>>nam;
                    flag=0;
                    cnt=0;
                    f.seekg(0,ios::beg);
                    while(f.read((char *)&t,sizeof(t)))
                    {

                        cnt++;
                        if(strcmp(t.getname(),nam)==0)
                        {
                            flag=1;
                            break;
                        }
                    }
                    f.clear();
                    if(flag==0)
                    {
                        cout<<endl<<"Record not found"<<endl;
                    }
                    else
                    {
                        int location=(cnt-1)*sizeof(t);
                        if(f.eof())
                            f.clear();
                        cout<<endl<<"Enter new telephone no. : ";
                        cin>>telno;
                        f.seekp(location);
                        t.update(nam,telno);
                        f.flush();
                        f.write((char *)&t,sizeof(t));
                    }

                    break;
            case 6:
                    return 6;
            default:
                    cout<<endl<<"INVALID INPUT"<<endl;
		}
    }

    return 0;
}
