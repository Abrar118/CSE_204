#include<bits/stdc++.h>
using namespace std;

template<class type> class Circular_queue
{
    type* a;
    int len, frnt, back, capacity;

    public:
        Circular_queue()
        {
            this->len=this->frnt=this->back=0;
            this->capacity=100;
            a=new type[100];
        }

        Circular_queue(int len)
        {
            this->len=this->frnt=this->back=0;
            this->capacity=len;
            a=new type[len];
        }

        bool underflow()
        {
            if(len) return false;
            return true;
        }

        bool overflow()
        {
            if(len==capacity) return true;
            return false;
        }

        void endqueue(type x)
        {
            if(!overflow())
            {
                a[back]=x;
                back=(back+1)%capacity;
                ++len;
            }
            else cout<<"Overflow"<<endl;
        }

        void dequeue()
        {
            if(!underflow())
            {
                frnt=(frnt+1)%capacity;
                --len;
            }
            else cout<<"Underflow"<<endl;
        }

        type front()
        {
            if(!underflow()) return a[frnt];
            return INT_MIN;
        }

        void print()
        {
            if(len)
            {
                cout<<"Front-> "<<a[frnt]<<" ";
                for(int i=(frnt+1)%capacity; i!=back; i=(i+1)%capacity) cout<<a[i]<<" ";
                cout<<"<-Back"<<endl<<endl;
            }
        }

        int size()
        {
            return len;
        }

        void clear()
        {
            delete[] a;
        }

        ~Circular_queue()
        {
            delete[] a;
        }
};

inline void menu()
{
    cout<<"0 - Exit."<<endl;
    cout<<"1 - Enqueue Item."<<endl;
    cout<<"2 - Dequeue Item."<<endl;
    cout<<"3 - View Front Item."<<endl;
    cout<<"4 - Display Items (Print Queue)."<<endl<<endl;
}

int main()
{
    Circular_queue<int> a(5);

    int choice, n;
    bool x=true;

    while(x)
    {
        menu();
        cout<<"Enter Choice: "; cin>>choice;

        switch(choice)
        {
            case 0: x=false; break;

            case 1: cout<<"Input element: "; cin>>n; 
                    if(!a.overflow()) a.endqueue(n);
                    else cout<<"Memory Overflow"<<endl<<endl;
                    break;

            case 2: if(!a.underflow()) a.dequeue();
                    else cout<<"Memory Underflow"<<endl;
                    cout<<endl; break;

            case 3: if(!a.underflow()) cout<<a.front()<<endl<<endl; break;

            case 4: if(!a.underflow()) a.print(); break;
        }
    }
    return 0;
}