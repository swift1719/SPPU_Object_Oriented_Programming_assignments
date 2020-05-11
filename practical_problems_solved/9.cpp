#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc<4)
	{
		cout<<"\n\t Insufficient number of arguments from command line.";
		return 1;
	}
	string data,newdata;
	fstream f;
	cout<<"\n\t Find word "<<argv[2]<<" and replace with "<<argv[3];
	cout<<"\n\t *** Contents of File Before Replacing ***"<<endl;
	f.open(argv[1],ios::in);
	if(!f)
    {
        cout<<endl<<"Unable to open\n";
        return 11;
    }
    while(f)
    {
        getline(f,data);
        cout<<data<<endl;
    }
    f.close();
    f.open(argv[1],ios::in);
    newdata="";
    if(!f)
    {
        cout<<endl<<"Unable to open\n";
        return 22;
    }
    while(f)
    {
        getline(f,data);
        int a;
        a=(int)data.find(argv[2],0);
        while(a!=string::npos)
        {
            data.replace(a,strlen(argv[2]),argv[3]);
            a=(int)data.find(argv[2],(a+1));
        }
        newdata=newdata+data+"\n";
    }
    f.close();
    f.open(argv[1],ios::out);
    if(!f)
    {
        cout<<endl<<"Unable to open\n";
        return 33;
    }
    f<<newdata;
    cout<<endl<<"Replaced\n";
    f.close();
    cout<<"\n\t *** Contents of File After Replacing ***"<<endl;
	f.open(argv[1],ios::in);
	if(!f)
	{
		cout<<"\n\t Unable to open a file.";
		return 1;
	}
	while(f)
	{
		getline(f,data);
		cout<<data<<endl;
	}
	f.close();
return 0;
}
