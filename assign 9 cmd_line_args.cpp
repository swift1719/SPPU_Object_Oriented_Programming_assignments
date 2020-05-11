#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main(int argc,char *argv[])
{

if(argc<4){
cout<<"\n Insufficient arguments\n";
return 0;
}
string d,n;
fstream fin;
cout<<"\n Find String "<<argv[2]<<" and replace with "<<argv[3];
cout<<"\n ***File Before Replacing***";
fin.open(argv[1],ios::in);
if(!fin){
cout<<"\n Unable to open";
return 0;
}
while(fin){
getline(fin,d);
cout<<d<<endl;
}
fin.close();
fin.open(argv[1],ios::in);
n="";
if(!fin) {
cout<<"\n Unable to open ";
return 1;
}
while(fin){
getline(fin,d);
int b;
int a=(int) d.find(argv[2],0);
while(a!=string::npos){
d.replace(a,strlen(argv[2]),argv[3]);
a=(int)d.find(argv[2],(a+1));
}
n=n+d+"\n";
}
fin.close();
fin.open(argv[1],ios::out);
fin<<n;
cout<<"\n\t Replacement Done Successfully.";
fin.close();
cout<<"\n\t *** Contents of File After Replacing ***";
fin.open(argv[1],ios::in);
if(!fin) {
cout<<"\n\t Unable to open a file.";
return 1;
}
while(fin){
getline(fin,d);
cout<<d<<endl;
}
fin.close();
return 0;
}

