#include<bits/stdc++.h>
//#include "utility.h"
#define endl "\n"
#define tab "\t"
#define pq priority_queue
#define in long long
#define dub double
#define dubb long double
const in modv=998244353;
using namespace std;

struct node
{
    int key;
    node *right, *left, *parent;
};

class BST
{
    node* root;
    int len;

    public:
        BST()
        {
            this->root=NULL, this->len=0;
        }

        void insert(int x,node* root)
        {
            if(this->root==NULL)
            {
                this->root=new node();
                this->root->left=this->root->right=NULL;
                this->root->key=x;
                this->root->parent=NULL;
            }
            else if(root->key>x)
            {
                if(root->left==NULL)
                {
                    node* temp=new node();
                    temp->right=temp->left=NULL;
                    temp->parent=root;
                    temp->key=x;

                    root->left=temp;
                    return;
                }
                else insert(x,root->left);
            }
            else
            {
                if(root->right==NULL)
                {
                    node* temp=new node();
                    temp->right=temp->left=NULL;
                    temp->parent=root;
                    temp->key=x;

                    root->right=temp;
                    return;
                }
                else insert(x,root->right);
            }
            
            ++this->len;
        }

        node* get_root()
        {
            return root;
        }

        void in_order_print(node* root)
        {
            if(root->left!=NULL) in_order_print(root->left);
            if(root!=NULL) cout<<root->key<<" ";
            if(root->right!=NULL) in_order_print(root->right);
        }


        void clear(node* root)
        {
            if(root->left!=NULL) clear(root->left);
            if(root->right!=NULL) clear(root->right);
            //cout<<"Cleared "<<root->key<<endl;
            delete root;
        }
};

vector<pair<int,int>>level(100);
queue<node*>q;

void level_count(node* root)
{
    level[root->key].first=0;
    level[0].second=1;
    q.push(root);

    while(!q.empty())
    {
        node* cur=q.front();
        q.pop();

        if(cur->left!=NULL)
        {
            level[cur->left->key].first=level[cur->key].first+1;
            ++level[level[cur->left->key].first].second;
            q.push(cur->left);
        }

        if(cur->right!=NULL)
        {
            level[cur->right->key].first=level[cur->key].first+1;
            ++level[level[cur->right->key].first].second;
            q.push(cur->right);
        }
    }
}

void level_order_print(node* parent)
{
    q.push(parent);
    int cnt=0,lev=0;
     
    while(!q.empty())
    {
        node* cur=q.front();
        q.pop();
        if(cur!=NULL) cout<<cur->key<<" ";
        
        if(++cnt==level[lev].second) cnt=0, ++lev, cout<<endl;

        if(cur->left!=NULL) q.push(cur->left);
        if(cur->right!=NULL) q.push(cur->right);
    }
}


int main()
{
    BST tree;
    int n,x; cin>>n;

    for(int i=0;i<n;++i) cin>>x, tree.insert(x,tree.get_root());

    level_count(tree.get_root());

    level_order_print(tree.get_root());
    
    tree.clear(tree.get_root());
    return 0;
}