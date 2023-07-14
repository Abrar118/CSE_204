#include<bits/stdc++.h>
#define endl "\n"
#define tab "\t"
using namespace std;

template<typename data> struct Double_Node
{
    data key;
    Double_Node* right;
    Double_Node* left;
};

template<typename data> class DoublyLinkedList
{
    Double_Node<data>* head=NULL;
    Double_Node<data>* tail=NULL;
    int asize=0;

    public:
        void insert_last(data x)
        {
            Double_Node<data>* temp=new Double_Node<data>();
            temp->key=x;

            if(head==NULL and tail==NULL)
            {
                temp->right=NULL;
                temp->left=NULL;
                head=tail=temp;
            }
            else
            {
                temp->right=NULL;
                temp->left=tail;
                tail->right=temp;
                tail=temp;
            }
            ++asize;
        }

        void insert_first(data x)
        {
            Double_Node<data>* temp=new Double_Node<data>();
            temp->key=x;

            if(head==NULL and tail==NULL)
            {
                temp->right=NULL;
                temp->left=NULL;
                head=tail=temp;
            }
            else
            {
                temp->right=head;
                temp->left=NULL;
                head->left=temp;
                head=temp;
            }
            ++asize;
        }

        void insert_after(Double_Node<data>* id, data x)
        {
            Double_Node<data>* temp=new Double_Node<data>();
            temp->key=x;

            if(head==NULL and tail==NULL)
            {
                temp->right=NULL;
                temp->left=NULL;
                head=tail=temp;
            }
            else
            {
                temp->right=id->right;
                temp->left=id;
                id->right=temp;
            }
            ++asize;
        }

        Double_Node<data>* find_first(data x)
        {
            Double_Node<data>* temp=head;

            while(temp!=NULL)
            {
                if(temp->key==x) break;
                temp=temp->right;
            }

            return temp;
        }

        Double_Node<data>* find_last(data x)
        {
            Double_Node<data>* temp=tail;

            while(temp!=NULL)
            {
                if(temp->key==x) break;
                temp=temp->left;
            }
            return temp;
        }

        void erase_first(data x)
        {
            Double_Node<data>* temp=head;

            if(head==NULL and tail==NULL) return;
            else if(asize==1)
            {
                if(head->key!=x) return;
                else
                {
                    head=tail=NULL;
                    free(temp);
                    --asize;
                }
            }
            else
            {
                if(head->key==x)
                {
                    head=head->right;
                    head->left=NULL;
                    free(temp);
                    --asize;
                }
                else if(tail->key==x)
                {
                    temp=tail;
                    tail=tail->left;
                    tail->right=NULL;
                    free(temp);
                    --asize;
                }
                else
                {
                    while(temp!=NULL)
                    {
                        if(temp->key==x) break;
                        else temp=temp->right;
                    }

                    temp->left->right=temp->right;
                    temp->right->left=temp->left;
                    free(temp);
                    --asize;
                }
            }
        }

        Double_Node<data>* get_head()
        {
            return head;
        }

        Double_Node<data>* get_tail()
        {
            return tail;
        }

        void print()
        {
            Double_Node<data>* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->key<<" ";
                temp=temp->right;
            }
            cout<<endl;
        }

        void clear()
        {
            Double_Node<data>* temp=head;
            Double_Node<data>* current=NULL;
            while(temp!=NULL)
            {
                current=temp->right;
                free(temp);
                temp=current;
            }
        }
};


int main()
{
    DoublyLinkedList<int>a;
    a.insert_first(1);
    a.insert_first(2);
    //a.erase_first(1);
    a.print();
    a.clear();
    return 0;
}