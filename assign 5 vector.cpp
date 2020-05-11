#include<iostream>
using namespace std;
template <class t>
class vect
{
    t *v;
    int s;
public:
    vect(int n)
    {
        s=n;
        v= new t[s];
    }
    void create();
    void display();
    void mod(int);
    void mul(int);
};

template <class t>
void vect<t>::create()
{
    cout<<endl<<"ENTER "<<s<<" ELEMENTS IN THE VECTOR: ";
    for(int j=0;j<s;j++)
    {
        cin>>v[j];
    }
}
template <class t>
void vect<t>::display()
{
    cout<<endl<<"\t***VECTOR***\n";
    for(int j=0;j<s;j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;
}
template <class t>
void vect<t>::mod(int i)
{
    if(i>=s)
    {
        cout<<endl<<"INDEX GREATER THAN VECTOR SIZE\nENTER VALID INDEX : ";
        cin>>i;
    }
    else if(i<0)
    {
        do
        {
            cout<<endl<<"INDEX CANNOT BE NEGATIVE\nENTER VALID INDEX : ";
            cin>>i;
        }while(i<0);
    }
    cout<<endl<<"ENTER A VALUE TO MODIFY: ";
    cin>>v[i];
}
template <class t>
void vect<t>::mul(int va)
{
    for(int j=0;j<s;j++)
        v[j]*=va;
}

main()
{
    int val,ind,si,ch,flag=0;
    cout<<"ENTER SIZE OF THE VECTOR: ";
    do
    {
        cin>>si;
        if(si<=0)
            cout<<endl<<"ENTER A VALUE GREATER THAN ZERO \n";
    }while(si<=0);
    vect<float> m(si);
    cout<<"###VECTOR###"<<endl;
    for(;;)
    {
        cout<<endl<<"PRESS:\n1.to create a vector\n2.to display \n3.to modify\n4.to multiply by a scalar\n5.to EXIT\n\tNOTE:FIRST CREATE A VECTOR THEN PERFORM OTHER OPERATIONS\n";
        cin>>ch;
        switch(ch)
        {
        case 1:m.create();
                flag=1;
            break;
        case 2: if(flag==0)
                {
                    cout<<endl<<"FIRST CREATE A VECTOR\n";
                }
                else
                {
                    m.display();
                }
            break;
        case 3: if(flag==0)
                {
                    cout<<endl<<"FIRST CREATE A VECTOR THEN MODIFY\n";
                }
                else
                {
                    cout<<"\nENTER INDEX OF VECTOR TO MODIFY: ";
                    cin>>ind;
                    m.mod(ind);
                }
            break;
        case 4: if(flag==0)
                {
                    cout<<endl<<"FIRST CREATE A VECTOR THEN MULTI[LY EITH SCALAR\n";
                }
                else
                {
                    cout<<endl<<"ENTER A SCALAR VALUE TO BE MULTIPLIED WITH : ";
                    cin>>val;
                    m.mul(val);
                }
            break;
        case 5: return 0;
            break;
        default: cout<<endl<<"ENTER VALID INPUT!!!";
            break;
        }

    }
}
