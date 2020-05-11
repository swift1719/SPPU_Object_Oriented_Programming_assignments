#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

class person
{
    public:
        char name[10];
        int phno;
        void input_data()
        {
            cout<<"\nEnter Name: ";
            cin>>name;
            cout<<"\nEnter telephone number: ";
            cin>>phno;
        }
        void put_data()
        {
           cout<<setw(20)<<name<<setw(10)<<phno<<endl;
        }
};

int main()
{
    person rec;
    int phone, pos, ch, offset, i;
    char nm[10];
    char ans;
    fstream fp;
    ifstream in;
    ofstream out;
    do
    {
         cout<<"\n\t\tMain Menu";
         cout<<"\n1.Read file\n2.Write file";
         cout<<"\n3.Determine name if telephone no. is specified";
         cout<<"\n4.Determine telephone no. if name is specified";
         cout<<"\n5.Update telephone number";
         cout<<"\nEnter your choice: ";
         cin>>ch;
         switch(ch)
         {
             case 1 :
                     in.open("test.txt", ios::in | ios::binary);
                     cout<<"\nThe contents of file are: ";
                  while(in.read((char *)&rec, sizeof(rec)))
                     {
                         rec.put_data();
                     }
                     in.close();
                     break;

              case 2 :
                     rec.input_data();
                     char ch;
                     cin.get(ch);
                     out.open("test.txt", ios::out | ios::app | ios::binary );
                     out.write((char *)&rec, sizeof(rec));
                     out.close();
                     break;

              case 3  :
                     cout<<"\nEnter telephone no.: ";
                     cin>>phone;
                     fp.open("test.txt", ios::ate | ios::in | ios::out | ios:: binary);
                     fp.seekg(0, ios::beg);

                     pos=-1; i=0;
                    while(fp.read((char *)&rec, sizeof(rec)))
                     {
                          if(phone==rec.phno)
                          {
                              pos=i;
                              break;
                          }
                          i++;
                    }
                    offset=pos*sizeof(rec);
                    fp.seekp(offset);
                    fp.read((char *)&rec, sizeof(rec));
                    cout<<"\nName is: "<<rec.name;
                    fp.close();
                    break;

              case 4 :
                     cout<<"\nEnter name: ";
                     cin>>nm;
                     fp.open("test.txt", ios::ate | ios::in | ios::out | ios:: binary);
                     fp.seekg(0, ios::beg);

                     pos=-1; i=0;
                     while(fp.read((char *)&rec, sizeof(rec)))
                     {
                          if((strcmp(nm,rec.name))==0)
                          {
                              pos=i;
                              break;
                          }
                          i++;
                    }
                    offset=pos*sizeof(rec);
                    fp.seekp(offset);
                    fp.read((char *)&rec, sizeof(rec));
                    cout<<"\nTelephone number is: "<<rec.phno;
                    fp.close();
                    break;

              case 5 :
                     cout<<"\nEnter name: ";
                     cin>>nm;
                     fp.open("test.txt", ios::ate | ios::in | ios::out | ios:: binary);
                     fp.seekg(0, ios::beg);

                     pos=-1; i=0;
                     while(fp.read((char *)&rec, sizeof(rec)))
                     {
                          if((strcmp(nm,rec.name))==0)
                          {
                              pos=i;
                              break;
                          }
                          i++;
                    }
                    offset=pos*sizeof(rec);
                    fp.seekp(offset);
                    cout<<"\nCurrent phone no.: "<<rec.phno;
                    cout<<"\nEnter new phone no.: ";
                    cin>>phone;
                    rec.phno=phone;
                    fp.write((char *)&rec, sizeof(rec))<<flush;
                    cout<<"\nRecord is updated";
                    fp.seekg(0);
                    while(fp.read((char *)&rec, sizeof(rec)))
                    {
                        rec.put_data();
                    }
                    fp.close();
                    break;
           }
           cout<<"\nDo you want to continue ? ";
           cin>>ans;
       }while(ans=='y' || ans =='Y');
       return 0;
  }
