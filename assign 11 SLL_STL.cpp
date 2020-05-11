#include <iostream>
#include <list>
#include <string>
using namespace std;
int main()
{
    int mylist[] = {1, 2, 3, 4, 5};
    list<int> l, l1 (mylist, mylist + sizeof(mylist) / sizeof(int));
    list<int>::iterator it;
    int choice, item;
    cout<<endl<<"List Implementation in STL"<<endl;

for(;;)
{
    cout<<endl<<"PRESS:";
    cout<<endl<<"1.to insert element at the Front"<<endl;
    cout<<"2.to Insert Element at the End"<<endl;
    cout<<"3.to Delete Element at the Front"<<endl;
    cout<<"4.to Delete Element at the End"<<endl;
    cout<<"5.get Front Element"<<endl;
    cout<<"6.get Last Element"<<endl;
    cout<<"7.to get size"<<endl;
    cout<<"8.to Resize List"<<endl;
    cout<<"9.Remove Elements with Specific Values"<<endl;
    cout<<"10.Remove Duplicate Values"<<endl;
    cout<<"11.Reverse the order of elements"<<endl;
    cout<<"12.Sort Forward List"<<endl;
    cout<<"13.Merge Sorted Lists"<<endl;
    cout<<"14.Display Forward List"<<endl;
    cout<<"15.Exit"<<endl;
    cin>>choice;

switch(choice){
        case 1:
            cout<<"Enter value to be inserted at the front: ";
            cin>>item;
            l.push_front(item);
            break;
        case 2:
            cout<<"Enter value to be inserted at the end: ";
            cin>>item;
            l.push_back(item);
            break;
        case 3:
            item = l.front();
            l.pop_front();
    cout<<"Element "<<item<<" deleted"<<endl;
            break;
        case 4:
            item = l.back();
            l.pop_back();
    cout<<"Element "<<item<<" deleted"<<endl;
            break;
        case 5:
   cout<<"Front Element of the List: ";
   cout<<l.front()<<endl;
            break;
        case 6:
            cout<<"Last Element of the List: ";
            cout<<l.back()<<endl;
            break;
        case 7:
            cout<<"Size of the List: "<<l.size()<<endl;
            break;
        case 8:
            cout<<"Enter new size of the List: ";
            cin>>item;
            if ( item <= l.size() )
                l.resize(item);
            else
                l.resize(item, 0);
            break;
        case 9:
            cout<<"Enter element to be deleted: ";
            cin>>item;
            l.remove(item);
            break;
        case 10:
            l.unique();
            cout<<"Duplicate Items Deleted"<<endl;
            break;
        case 11:
            l.reverse();
            cout<<"List reversed"<<endl;
            break;
        case 12:
            l.sort();
            cout<<"List Sorted"<<endl;
            break;
        case 13:
            l1.sort();
            l.sort();
            l.merge(l1);
            cout<<"Lists Merged after sorting"<<endl;
            break;
        case 14:
            cout<<"Elements of the List:  ";
            for (it = l.begin(); it != l.end(); it++)
                cout<<*it<<"  ";
            cout<<endl;
            break;
case 15:
            return 0;
  break;
default:
            cout<<"Wrong Choice"<<endl;
        }
}
    return 0;
}
