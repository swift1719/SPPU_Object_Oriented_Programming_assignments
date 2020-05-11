#include<iostream>
#include<fstream>
using namespace std;
main()
{
    char ch;
    string data;
    fstream file;
    file.open("asd.txt",ios::in);
    if(!file)
    {
        cout<<endl<<"UNABLE to open a file\n";
        return 0;
    }
    cout<<"CONTENTS of file : \n";
    while(!file.eof())
    {
        getline(file,data);
        cout<<data<<endl;
    }
    file.close();
    cout<<"Enter character to check as first character of the line: ";
    cin>>ch;
    file.open("asd.txt",ios::in);
    int cnt=0,t=0;
    while(!file.eof())
    {
        t++;
        getline(file,data);
        if(data[0]==ch)
            cnt++;
    }
    cout<<endl<<"LINES starting with "<<ch<<" are : "<<cnt<<endl;
    file.close();
    cout<<"Enter character to check as first character of the WORD: ";
    cin>>ch;
    file.open("asd.txt",ios::in);
    cnt=0;
    while(!file.eof())
    {
        file>>data;
        if(data[0]==ch)
            cnt++;
    }
    cout<<endl<<"WORDS starting with "<<ch<<" are : "<<cnt<<endl;
    file.close();

    return 0;
}
