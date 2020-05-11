#include<iostream>
#include<iomanip>
using namespace std;
main()
{
    cout.setf(ios::showpoint);
    cout<<setw(5)<<"n"<<setw(15)<<"INVERSE_OF_SUM"<<setw(15)<<"Sum_OF_Terms"<<endl;
    double term,sum=0;
    for(int i=1;i<11;i++)
    {
        term=1.0/float(i);
        sum+=term;
        cout<<setprecision(4)<<setw(5)<<i<<setw(14)<<setiosflags(ios::scientific)<<term<<resetiosflags(ios::scientific)<<setprecision(4)<<setw(13)<<sum<<endl;
    }
return 0;
}
