#include<iostream>
#include<list>
using namespace std;
void display(list<int> &lst)
{
    cout<<endl;
    if(lst.empty())
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        list<int> ::iterator i;
        for(i=lst.begin();i!=lst.end();i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
}
void mul(list<int> &lst,int y)
{
    list<int>::iterator p;
    for(p=lst.begin();p!=lst.end();++p)
    {
        *p=((*p) * y);
    }
}
int main()
{
    list<int>l,l2;
    int ch,x,n;
    list<int> A,B;
    cout<<"\n\t***LIST***\n";
    for(;;)
    {
        cout<<endl<<"PRESS:\n1) Insert Element at the Front\n2) Insert Element at the End\n3) Delete Element at the Front\n4) Delete Element at the End\n5) Remove Elements with Specific Values\n6) Multiply with Scalar value\n7) Reverse the order of elements\n8) Sort Forward List\n9) Merge Sorted Lists\n10) Display Forward List\n11.to EXIT"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1: cout<<"Enter a element to be added at front: ";
                cin>>x;
                l.push_front(x);
                display(l);
            break;
        case 2:  cout<<"Enter a element to be added at end: ";
                cin>>x;
                l.push_back(x);
                display(l);
            break;
        case 3: cout<<endl;
                if(l.empty())
                {
                    cout<<"EMPTY"<<endl;
                    break;
                }
                l.pop_front();
                cout<<"Front element deleted\n";
                display(l);
            break;
        case 4:
                cout<<endl;
                if(l.empty())
                {
                    cout<<"EMPTY"<<endl;
                    break;
                }
                l.pop_back();
                cout<<"End element deleted\n";
                display(l);
            break;
        case 5:
                cout<<endl;
                if(l.empty())
                {
                    cout<<"EMPTY"<<endl;
                    break;
                }
                cout<<"Enter a element to remove: ";
                cin>>x;
                l.remove(x);
                display(l);
            break;
        case 6:
                cout<<endl;
                if(l.empty())
                {
                    cout<<"EMPTY"<<endl;
                    break;
                }
                cout<<"Enter a no. to be multiplied with: ";
                cin>>x;
                B=l;
                mul(B,x);
                display(B);
            break;
        case 7:
                cout<<endl;
                if(l.empty())
                {
                    cout<<"EMPTY"<<endl;
                    break;
                }
                cout<<"REVERSED LIST"<<endl;
                B=l;
                B.reverse();
                display(B);
            break;
        case 8: cout<<endl;
                if(l.empty())
                {
                    cout<<"EMPTY"<<endl;
                    break;
                }
                cout<<"SORTED LIST"<<endl;
                B=l;
                B.sort();
                display(B);
            break;
        case 9: cout<<"Enter no. of elements in list 2: ";
                cin>>n;
                A=l;
                cout<<"Enter "<<n<<" elements in list 2\n";
                for(int i=0;i<n;i++)
                {
                    cout<<"Enter a value: ";
                    cin>>x;
                    l2.push_back(x);
                }
                l2.sort();
                A.sort();
                cout<<endl<<"Sorted list 2: ";
                A.merge(l2);
                display(A);
            break;
        case 10:    display(l);
            break;
        case 11:    return 1;
            break;
        default:
            cout<<"invalid input"<<endl;
        }
    }
    return 0;
}
