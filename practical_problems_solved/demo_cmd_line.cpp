//Demonstration of command line arguments for Renaming of file name
#include <iostream>
#include<cstring>
using namespace std;
int main(int argc,char *argv[])
{
	if(argc<3)
	{
		cout<<"\n Insufficient Arguments.";
		return 1;
	}
	char oldname[50],newname[50];
	strcpy(oldname,argv[1]);
	strcpy(newname,argv[2]);
	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("\n Error renaming file.");
	else
		cout << "\n\t File renamed successfully.";
	return 0;
}
