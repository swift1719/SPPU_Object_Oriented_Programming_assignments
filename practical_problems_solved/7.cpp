#include<bits/stdc++.h>
using namespace std;
class personal
{
protected:
    int contact,age;
    string name,address,gender;
public:
    personal()
    {
        contact=-1;
        age=-1;
        name="";
        address="";
        gender="";
    }
    void ip()
    {
        cout<<endl<<"\t***Enter personal details***\nNAME: ";
        cin>>name;
        cout<<"AGE: ";
        cin>>age;
        cout<<"GENDER: ";
        cin>>gender;
        cout<<"ADDRESS: ";
        cin>>address;
        cout<<"CONTACT: ";
        cin>>contact;
    }
    void op()
    {
        cout<<endl<<"\t*****PERSONAL DETAILS*****\nNAME: "<<name<<endl<<"AGE : "<<age<<endl<<"GENDER : "<<gender<<endl<<"ADDRESS : "<<address<<endl<<"CONTACT No.: "<<contact<<endl;
    }
};
class prof
{
protected:
    string lang,project,fl,it;
public:
    prof()
    {
        lang="";
        project="";
        fl="";
        it="";
    }
    void ip()
    {
        cout<<endl<<"\t***Enter professional details***\nMASTERED PROGRAMMING LANGUAGE: ";
        cin>>lang;
        cout<<"FORIEGN LANGUAGE: ";
        cin>>fl;
        cout<<"PROJECT: ";
        cin>>project;
        cout<<"INTERNSHIP: ";
        cin>>it;
    }
    void op()
    {
        cout<<endl<<"\t*****PROFESSIONAL DETAILS*****\nMASTERED PROGRAMIING LANGUAGE: "<<lang<<endl<<"FORIEGN LANGUAGE : "<<fl<<endl<<"PROJECT : "<<project<<endl<<"INTERNSHIP : "<<it<<endl;
    }
};
class acad
{
protected:
    string qual,col;
    float perc;
public:
    acad()
    {
        col="";
        qual="";
        perc=-1;
    }
    void ip()
    {
        cout<<endl<<"\t***Enter academic details***\nHIGHEST QUALIFICATION: ";
        cin>>qual;
        cout<<"PERCENTAGE: ";
        cin>>perc;
        cout<<"COLLEGE: ";
        cin>>col;
    }
    void op()
    {
        cout<<endl<<"\t*****ACADEMIC DETAILS*****\nHIGHEST QUALIFICATION: "<<qual<<endl<<"PERCENTAGE : "<<perc<<"% "<<endl<<"COLLEGE: "<<col<<endl;
    }

};
class cv:protected personal,protected prof,protected acad
{
protected:
    string title;
public:
    cv():personal(),prof(),acad()
    {
        title="";
    }
    void ip()
    {
        cout<<endl<<"ENTER TITLE: ";
        cin>>title;
        personal::ip();
        prof::ip();
        acad::ip();
    }
    void op()
    {
        cout<<endl<<"\n\n\t*****"<<title<<"*****";
        personal::op();
        prof::op();
        acad::op();
    }
};
int main()
{
    cv c;
    c.ip();
    c.op();
return 0;
}
