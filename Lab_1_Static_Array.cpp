#include<bits/stdc++.h>
#define endl "\n"
#define tab "\t"
using namespace std;

//ID: 202114003 Abrar Mahir Esam

struct static_array
{
    int a[10000], size=0;

    void print()
    {
        if(!size) cout<<"The array is empty"<<endl;
        else for(int i=0;i<size;++i) cout<<i<<" : "<<a[i]<<endl;
    }

    void insert_at_first(int x)
    {
        if(size+1==10000) cout<<"Array size overload"<<endl;
        else
        {
            for(int i=size;i>-1;--i) a[i]=a[i-1];
            a[0]=x, ++size;
        }
    }

    void insert_at_last(int x)
    {
        if(size+1==10000) cout<<"Array size overload"<<endl;
        else a[size]=x, ++size;
    }

    void insert_at_any(int id,int x)
    {
        if(size+1==10000) cout<<"Array size overload"<<endl;
        else if(id>size) cout<<"Index "<<id<<" is not accessible"<<endl;
        else
        {
            for(int i=size;i>id;--i) a[i]=a[i-1];
            a[id]=x, ++size;
        }
    }

    int delete_at_first()
    {
        if(!size) cout<<"Array is empty!"<<endl;
        else
        {
            int x=a[0];
            for(int i=0;i<size;++i) a[i]=a[i+1];
            --size;
            return x;
        }
        return 0;
    }

    int delete_at_last()
    {
        if(!size) cout<<"Array is empty!"<<endl;
        else return a[--size];
        return 0;
    }

    int delete_at_any(int id)
    {
        int x=a[id];
        if(!size) cout<<"Array is empty!"<<endl;
        else if(id>size) cout<<"Index "<<id<<" is not accessible"<<endl;
        else
        {
            for(int i=id;i<size;++i) a[i]=a[i+1];
            --size;
            return x;
        }
        return 0;
    }

    int find(int x)
    {
        int id=-1;
        for(int i=0;i<size;++i)
        {
            if(a[i]==x)
            {
                id=i; break;
            }
        }
        return id;
    }

    void rotate_left()
    {
        int x=a[0];
        for(int i=0;i<size-1;++i) a[i]=a[i+1];
        a[size-1]=x;
    }

    void rotate_right()
    {
        int x=a[size-1];
        for(int i=size-1;i>-1;--i) a[i]=a[i-1];
        a[0]=x;
    }

    void sort()
    {
        bool state;
        for(int i=0;i<size-1;i++)
        {
            state=false;
            for(int k=0;k<size-i-1;k++)
            {
                if(a[k]>a[k+1])
                {
                    swap(a[k],a[k+1]), state = true;
                }
            }
            if(!state) break;
        }
    }

    void clear()
    {
        size=0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    static_array a;
    a.print();
    a.insert_at_last(10);
    a.insert_at_first(20);
    a.insert_at_last(30);
    a.insert_at_last(40);
    a.insert_at_first(50);
    a.insert_at_last(60);
    a.print();

    cout<<endl;

    a.delete_at_last();
    a.delete_at_first();
    a.delete_at_first();
    a.delete_at_last();
    a.print();

    cout<<endl;

    a.insert_at_any(0,60);
    a.insert_at_any(5,60);
    a.insert_at_any(3,60);
    a.print();

    cout<<endl;

    a.delete_at_any(0);
    a.delete_at_any(5);
    a.delete_at_any(2);
    a.print();

    cout<<endl;

    a.rotate_left();
    a.rotate_right();
    a.print();

    cout<<endl;

    a.sort();
    a.print();
    return 0;
}