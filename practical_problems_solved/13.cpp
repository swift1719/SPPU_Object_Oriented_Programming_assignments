#include<iostream>
using namespace std;
template <class t>
class sorting
{
     t *v,temp;
     int s;
 public:
    sorting(int n)
    {
        this->s=n;
        this->v=new t[s];
    }
    void ip();
    void display();
    void ssort();
 };
template<class t>
void sorting<t>::ip()
{
    cout<<endl<<"ENTER "<<s<<" ELEMENTS IN THE ARRAY: ";
    for(int i=0;i<s;i++)
     {
         cin>>v[i];
     }
}
template<class t>
void sorting<t>::display()
{
    for(int i=0;i<s;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
template<class t>
void sorting<t>::ssort()
{
    int i,j,min;
    for(i=0;i<s-1;i++)
    {
        min=i;
        for(j=i+1;j<s;j++)
        {
            if(v[j]<v[min])
                min=j;
        }
        if(i!=min)
        {
            temp=v[i];
            v[i]=v[min];
            v[min]=temp;
        }
    }
}
 main()
 {
     int si;
     cout<<endl<<"ENTER SIZE OF THE ARRAY: ";
     cin>>si;
     sorting<int>s1(si);
     s1.ip();
     cout<<endl<<"UNSORTED ARRAY\n";
     s1.display();
     s1.ssort();
     cout<<endl<<"SORTED ARRAY\n";
     s1.display();

     cout<<endl<<"ENTER SIZE OF THE ARRAY: ";
     cin>>si;
     sorting<float>s2(si);
     s2.ip();
     cout<<endl<<"UNSORTED ARRAY\n";
     s2.display();
     s2.ssort();
     cout<<endl<<"SORTED ARRAY\n";
     s2.display();

     return 0;
 }
