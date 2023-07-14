#include<bits/stdc++.h>
using namespace std;

template<class type> class Node
{
    private:
        type val;
        Node *next;

    public:
        Node()
        {
            next = NULL;
        }

        type get_value()
        {
            return val;
        }

        void set_value(type x)
        {
            this->val=x;
        }

        Node* get_next()
        {
            return this->next;
        }

        void set_next(Node* next)
        {
            this->next=next;
        }
};

template<class type> class Stack
{
    private:
        Node<type>* top;
        int s_size;

    public:
        Stack()
        {
            top = NULL;
            s_size = 0;
        }

        void push(int n)
        {
            ///Stack functionality: Inserts n in the stack
            ///Linked list functionality: Creates aNode<type> and inserts at the head of the list

            Node<type>* a_node=new Node<type>();
            a_node->set_value(n);
            a_node->set_next(top);
            top=a_node;
            ++s_size;
        }

        bool is_empty()
        {
            ///Stack functionality: Returns true if the stack is empty, otherwise returns false
            return s_size==0;
        }

        int show_top()
        {
            ///Stack functionality: Returns the last inserted value/top value of the stack (doesn't remove from stack)
            ///Linked list functionality: Returns the value located at head
            ///If the user calls this function for an empty stack, it will generate runtime error

            return top->get_value();
        }

        void pop()
        {
            ///Stack functionality: Removes the top value of the stack
            ///Linked list functionality: if the list is not empty then removes theNode<type> under head and declares new head
            ///If the user calls this function for an empty stack, it will generate runtime error

            if(!s_size) return;

            Node<type>* temp=top;
            top=top->get_next();
            free(temp);
            --s_size;
        }

        int size()
        {
            ///Returns the size of stack
            return s_size;
        }

        void display_stack()
        {
            ///Prints the stack
            Node<type>* temp=top;
            cout<<"Top -> ";
            while(temp!=NULL) cout<<temp->get_value()<<" ", temp=temp->get_next();
            cout<<endl<<endl;
        }

        void clear()
        {
            Node<type>* temp=top;
            Node<type>* current=NULL;
            while(temp!=NULL)
            {
                current=temp->get_next();
                free(temp);
                temp=current;
            }
        }
};


int main()
{
    int choice, val;
    bool x=true, file_input;

    cout<<endl<<"Press 1 to input in console or press 2 to take input from demo input file: ";
    cin>>choice;
    if(choice==1) file_input=true;
    else file_input=false;

    ifstream in("input.txt");

    Stack<int>s;

    while(x)
    {
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - View Top Item."<<endl;
        cout<<"4 - Size of Stack."<<endl;
        cout<<"5 - Display Items (Print STACK)."<<endl<<endl;

        cout<<"Enter your choice: ";
        if(file_input) cin>>choice;
        else
        {
            in>>choice;
            cout<<choice<<endl;
        }

        switch(choice)
        {
            case 0:
                x=false; s.clear(), in.close();
                break;

            case 1:
                cout<<"Input element: ";
                if(file_input) cin>>val;
                else
                {
                    in>>val;
                    cout<<val<<endl;
                }
                s.push(val);
                break;

            case 2:
                ///Must check whether the stack is empty or not before popping
                if(!s.is_empty()) s.pop();
                break;

            case 3:
                ///Must check whether the stack is empty or not before viewing top item
                if(!s.is_empty()) cout<<"Top element: "<<s.show_top()<<endl;
                break;

            case 4:
                cout<<"Size of the stack: "<<s.size()<<endl;
                break;

            case 5:
                s.display_stack();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }

        cout<<endl<<endl;
    }
    return 0;
}
