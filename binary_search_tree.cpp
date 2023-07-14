#include<bits/stdc++.h>
using namespace std;

struct bs_node
{
    int key;
    bs_node *right, *left, *parent;

    public:
        bs_node(int key,bs_node* parent=NULL)
        {
            this->key=key;
            this->left=this->right=NULL;
            this->parent=parent;
        }
};

class BST
{
    bs_node* root;
    bs_node* data;
    int len;
    //int* height;

    public:
        BST()
        {
            this->root=NULL, this->len=0;
            this->data=this->root;
        }

        void insert(int x)
        {
            if(this->root==NULL)
            {
                this->root=new bs_node(x);

                this->data=this->root;
                return;
            }
            else
            {
                if(data->key>x)
                {
                    if(data->left==NULL)
                    {
                        bs_node* temp=new bs_node(x,data);

                        data->left=temp;
                        this->data=this->root;
                        return;
                    }
                    else data=data->left, insert(x);
                }
                else
                {
                    if(data->right==NULL)
                    {
                        bs_node* temp=new bs_node(x,data);

                        data->right=temp;
                        this->data=this->root;
                        return;
                    }
                    else data=data->right, insert(x);
                }
            }
            ++this->len;
        }

        void erase(bs_node* temp)
        {
            if(temp==NULL) return;

            if(temp->left==NULL and temp->right==NULL)
            {
                if(temp==this->root)
                {
                    delete temp, this->root=NULL;
                    return;
                }

                if(temp->parent->key>temp->key) temp->parent->left=NULL;
                else temp->parent->right=NULL;

                delete temp;
                return;
            }
            else if(temp->left==NULL or temp->right==NULL)
            {
                bs_node* child;
                if(temp->left==NULL) child=temp->right;
                else child=temp->left;

                if(temp==root)
                {
                    delete temp;
                    this->root=child;
                    child->parent=NULL;
                    return;
                }

                child->parent=temp->parent;

                if(temp->parent->key>temp->key) temp->parent->left=child;
                else temp->parent->right=child;

                delete temp;
                return;
            }

            ////for bs_node with double children
            bs_node* data=min_of_tree(temp->right);
            int x=data->key;
            erase(data);
            temp->key=x;
        }

        void erase(int x)
        {
            bs_node* temp=find(x);
            erase(temp);
        }

        bs_node* find(int x)
        {
            bs_node* temp=this->root;

            while(temp!=NULL)
            {
                if(x==temp->key) break;
                else if(x<temp->key) temp=temp->left;
                else temp=temp->right;
            }

            return temp;
        }

        bs_node* min_of_tree(bs_node* root)
        {
            while(root and root->left!=NULL) root=root->left;
            return root;
        }

        bs_node* max_of_tree(bs_node* root)
        {
            while(root and root->right!=NULL) root=root->left;
            return root;
        }

        int height(bs_node* temp)
        {
            int x=0;
            while(temp!=this->root) ++x, temp=temp->parent;
            return x;
        }

        bs_node* get_root()
        {
            return this->root;
        }

        int size()
        {
            return this->len;
        }

        void in_order_print(bs_node* root)
        {
            if(this->root!=NULL)
            {
                if(root->left!=NULL) in_order_print(root->left);
                if(root!=NULL) cout<<root->key<<" ";
                if(root->right!=NULL) in_order_print(root->right);
            }
        }

        void clear(bs_node* temp)
        {
            if(this->root!=NULL)
            {
                if(temp->left!=NULL) clear(temp->left);
                if(temp->right!=NULL) clear(temp->right);
                cout<<"Cleared "<<temp->key<<endl;
                delete temp;
            }
        }
};

int main()
{
    BST a;
    int n,x,k; cin>>n;
    while(n--) cin>>x, a.insert(x);
    a.in_order_print(a.get_root());
    cout<<endl;
    
    cin>>n;
    while(n--)
    {
        cin>>x;
        a.erase(x);
        a.in_order_print(a.get_root());
        cout<<endl;
    }

    a.clear(a.get_root());
    return 0;
}