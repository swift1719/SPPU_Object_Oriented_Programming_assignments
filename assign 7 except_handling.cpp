#include<iostream>
using namespace std;
class user
{
  int age;
  float income;
  string city,vehicle;
public:
    void ip();
    void checkage();
    void checkincome();
    void checkcity();
    void checkvehicle();
    void op();
};
void user::ip()
{
    cout<<endl<<"ENTER AGE OF USER(18 to 55): ";
    cin>>age;
    cout<<"ENTER INCOME OF USER(Rs 50,000 - 1,00,000 /-): ";
    cin>>income;
    cout<<"ENTER CITY OF USER(pune/mumbai/bangalore/chennai): ";
    cin>>city;
    cout<<"ENTER VEHICLE USED BY USER(four): ";
    cin.ignore();
    getline(cin,vehicle);

}
void user::checkage()
{
    try
    {
        if(age<18 || age>55)
            throw age;
    }
    catch(int i)
    {
        cout<<endl<<"AGE DOES NOT MEETS THE CRITERION\n";
    }
}
void user::checkcity()
{
    int flag=0;

    try
    {
        if((city.compare("pune")==0) || (city.compare("mumbai")==0) || (city.compare("bangalore")==0) || (city.compare("chennai")==0))
            flag=1;
        if(flag==0)
        {
            throw city;
        }
    }
    catch(string v)
    {
        cout<<endl<<"CITY DOES NOT MEETS THE CRITERION\n";
    }
}
void user::checkincome()
{
    try
    {
        if(income>100000 || income<50000)
            throw income;
    }
    catch(float t)
    {
        cout<<endl<<"INCOME DOES NOT MEETS THE CRITERION\n";
    }
}
void user::checkvehicle()
{
    char x;
    try
    {
        if(vehicle.compare("four wheeler")!=0)
            throw x;
    }
    catch(char c)
    {
        cout<<endl<<"VEHICLE DOES NOT MEETS THE CRITERION\n";
    }
}
void user::op()
{
    cout<<endl<<"AGE: "<<age<<endl<<"INCOME: "<<income<<endl<<"CITY: "<<city<<endl<<"VEHICLE: "<<vehicle<<endl;
}
main()
{
    user o;
    o.ip();
    o.op();
    o.checkage();
    o.checkincome();
    o.checkcity();
    o.checkvehicle();

    return 0;
}
