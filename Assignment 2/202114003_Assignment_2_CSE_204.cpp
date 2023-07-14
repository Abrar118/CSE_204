#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define endl "\n"
#define tab "\t"
using namespace std;

//ID: 202114003 Abrar Mahir Esam

struct StudentData
{
    char name[100];
    long long id;
    double number;
};

typedef StudentData sdd;

struct dynamic_array
{
    int asize=0, CapLimit=5;
    sdd* a=(sdd*)malloc(CapLimit*sizeof(sdd));

    void insertDataAtLast()
    {
        cout<<"Student Name: "; cin>>a[asize].name;
        cout<<"Student ID: "; cin>>a[asize].id;
        cout<<"Mark: "; cin>>a[asize].number;

        ++asize;
        if(asize==CapLimit) a=(sdd*)realloc(a,(CapLimit+=5)*sizeof(sdd));
    }

    void insertDataAtFirst()
    {
        for(int i=asize;i>-1;--i) a[i]=a[i-1];

        cout<<"Student Name: "; cin>>a[0].name;
        cout<<"Student ID: "; cin>>a[0].id;
        cout<<"Mark: "; cin>>a[0].number;

        ++asize;
        if(asize==CapLimit) a=(sdd*)realloc(a,(CapLimit+=5)*sizeof(sdd));
    }

    void insertDataAtAny(int pos)
    {
        if(pos>asize) cout<<"Index "<<pos<<" cannot be accessed"<<endl;
        else
        {
            for(int i=asize;i>pos;--i) a[i]=a[i-1];
            cout<<"Student Name: "; cin>>a[pos].name;
            cout<<"Student ID: "; cin>>a[pos].id;
            cout<<"Mark: "; cin>>a[pos].number;
        }

        ++asize;
        if(asize==CapLimit) a=(sdd*)realloc(a,(CapLimit+=5)*sizeof(sdd));
    }

    sdd deleteDataAtFirst()
    {
        sdd temp;
        if(!asize)
        {
            cout<<"Array is empty!"<<endl; return temp;
        }
        else
        {
            temp=a[0];
            for(int i=0;i<asize-1;++i) a[i]=a[i+1];
            --asize;
        }
        return temp;
    }

    sdd deleteDataAtAny(int pos)
    {
        sdd temp;
        if(!asize) 
        {
            cout<<"Array is empty!"<<endl; return temp;
        }
        else if(pos>asize) 
        {
            cout<<"Index "<<pos<<" is not accessible"<<endl; return temp;
        }
        else
        {
            temp=a[pos];
            for(int i=pos;i<asize-1;++i) a[i]=a[i+1];
            --asize;
        }
        return temp;
    }

    sdd deleteDataAtLast()
    {
        if(!asize) 
        {
            cout<<"Array is empty!"<<endl; return a[asize];
        }
        return a[--asize];
    }

    void print()
    {
        for(int i=0;i<asize;++i)
        {
            cout<<"--------------------------------------"<<endl;
            cout<<"Student Name: "<<a[i].name<<endl;
            cout<<"Student ID: "<<a[i].id<<endl;
            cout<<"Mark: "<<fixed<<setprecision(2)<<a[i].number<<endl;
            cout<<"--------------------------------------"<<endl;
        }
    }
    void clear()
    {
        free(a);
    }
};

void menu()
{
    cout<<endl<<"1. Enter Student's Data At First"<<endl;
    cout<<"2. Enter Student's Data At A Given Position"<<endl;
    cout<<"3. Enter Student's Data At Last"<<endl;
    cout<<"4. Show Students' Data"<<endl;
    cout<<"5. Delete Student's Data from First"<<endl;
    cout<<"6. Delete Student's Data From A Given Position"<<endl;
    cout<<"7. Delete Student's Data At Last Position"<<endl;
    cout<<"8. Exit"<<endl<<endl;
}

int main()
{

    dynamic_array CSE_21;
    int temp,i;
    menu();
    while(cin>>temp,temp!=8)
    {
        switch(temp)
        {
            case 1: CSE_21.insertDataAtFirst(); break;
            case 2: cout<<"Enter Index: "; cin>>i; CSE_21.insertDataAtAny(i); break;
            case 3: CSE_21.insertDataAtLast(); break;
            case 4: CSE_21.print(); break;
            case 5: CSE_21.deleteDataAtFirst(); break;
            case 6: cout<<"Enter Index: "; cin>>i; CSE_21.deleteDataAtAny(i); break;
            case 7: CSE_21.deleteDataAtLast(); break;
        }
        menu();
    }
    CSE_21.clear();
    return 0;
}