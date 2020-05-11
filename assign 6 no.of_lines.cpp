#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string data;
	char ch;
	ifstream fin("abc.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t ERROR";
		return 0;
	}
	cout<<"\n Input File is:\n";
	while(!fin.eof())
	{
		getline(fin,data);
		cout<<data<<endl;
	}
	fin.close();
	cout<<endl<<"Enter a character to check: ";
	cin >> ch;
	fin.open("abc.txt",ios::in);
	int cnt=0;
	while(!fin.eof())
	{
		getline(fin,data);
		if(data[0]==ch)
			cnt++;
	}
	cout<<endl<<"lines which starts with "<<ch<<" : "<<cnt<<endl;
	fin.close();
	return 0;
}
