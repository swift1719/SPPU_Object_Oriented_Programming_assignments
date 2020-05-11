#include<iostream>
#include<string.h>
using namespace std;
class publication
{
protected:
    string title;
    float price;
public:
    void get()
    {
        cout<<endl<<"ENTER TITLE: ";
        cin>>title;
        cout<<endl<<"ENTER PRICE: ";
        cin>>price;
    }
    void put(int f)
    {
        if(f==0)
        {
        int le;
        le=title.length();
        try
        {
            if(le<3)
                throw le;
            if(price<0)
                throw price;
        }
        catch(int l)
        {
            cout<<endl<<"LENGTH OF TITLE LESS THAN THREE \n";
            title="0";
            price=0;
        }
        catch(float p)
        {
            cout<<endl<<"PRICE CANNOT BE NEGATIVE \n";
            price=0;
            title="0";
        }

        }
        cout<<endl<<"TITLE: "<<title<<endl<<"PRICE: "<<price<<endl;
    }
};
class book:protected publication
{
protected:
    int pg_cnt;
public:
    book()
    {
        pg_cnt=0;
    }
    void get()
    {
        publication::get();
        cout<<endl<<"ENTER NO. OF PAGES IN THE BOOK: ";
        cin>>pg_cnt;
    }
    void put()
    {
        int flag=0;
        try
        {
            if(pg_cnt<0)
                throw pg_cnt;
        }
        catch(int a)
        {
            pg_cnt=0;
            cout<<endl<<"NO. OF PAGES CANNOT BE NEGATIVE \n";
            publication::title="0";
            publication::price=0;
            flag=1;
        }
        publication::put(flag);
        if((publication::title.compare("0"))==0 || publication::price==0)
            pg_cnt=0;
        cout<<"NO. OF PAGES: "<<pg_cnt<<endl;
    }
};
class tape:protected publication
{
protected:
    float time;
public:
    tape()
    {
        time=0;
    }
    void get()
    {
        publication::get();
        cout<<endl<<"ENTER TIME IN MINUTES: ";
        cin>>time;
    }
    void put()
    {
        int fl=0;
        try
        {
            if(time<0)
                throw time;
        }
        catch(float t)
        {
            cout<<endl<<"TIME CANNOT BE NEGATIVE";
            time=0;
            fl=1;
            publication::title="0";
            publication::price=0;
        }
        publication::put(fl);
        if((publication::title.compare("0"))==0 || publication::price==0)
            time=0;
        cout<<"TIME: "<<time<<endl;
    }
};
main()
{
    book b1;
    tape t1;
    b1.get();
    b1.put();
    t1.get();
    t1.put();

    return 0;
}
