#include<bits/stdc++.h>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc<3)
    {
    cout<<endl<<"NOT SUFFICIENT ARGUMENTS"<<endl;
    return 1;
    }
    char old[20],n[20];
    strcpy(old,argv[1]);
    strcpy(n,argv[2]);
    if(rename(old,n)!=0)
        perror("\nERROR RENAMING\n");
    else
        cout<<"\nREPLACED!!!\n";
    return 0;
}

