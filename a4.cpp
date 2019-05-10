/*
    Balaji Gavhane
    203248
    Batch B1
*/
#include<iostream>
using namespace std;
class node{
    char data;
    node *left;
    node *right;
    int lbit;
    int rbit;
    node()
    {
        lbit=rbit=1;
    }
    friend class tree;
};
class tree
{
    node *root,*head;
    public:
    void create();
    void preorder();
    void inorder();
    node* insucc(node*);
    tree()
    {
        root=NULL;
        head=new node();
        head->left=head->right=head;
    }

};
void tree::create()
{
    char ch,choice;
    int flag=0;
    node *curr,*temp;
    do
    {
        if(root==NULL)
        {
            //head=new node();
            root=new node();
            cout<<"Enter data : \n";
            cin>>root->data;
            head->left=root;
            head->lbit=head->rbit=0;
            root->left=root->right=head;
            //head->right=head;
        }
        else
        {
            temp=root;
            curr=new node();
            cout<<"Enter data : \n";
            cin>>curr->data;
            while(flag==0)
            {
                cout<<"Where do you want to add (l/r) of "<<temp->data<<endl;
                cin>>ch;
                if(ch=='l')
                {
                    if(temp->lbit==1)
                    {
                        curr->left=temp->left;
                        curr->right=temp;
                        temp->left=curr;
                        temp->lbit=0;
                        flag=1;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else if(ch=='r')
                {
                    if(temp->rbit==1)
                    {
                        curr->left=temp;
                        curr->right=temp->right;
                        temp->right=curr;
                        temp->rbit=0;
                        flag=1;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
        }
        flag=0;
        cout<<"Do you want to add another node?(y/n)\n";
        cin>>choice;
    }
    while(choice=='y');
}
void tree::preorder()
{
    node *temp;
    temp=head->left;
    cout<<"Preorder : ";
    while(temp!=head)
    {
        cout<<temp->data;
        while(temp->lbit==0)
        {
            temp=temp->left;
            cout<<temp->data;
        }
        while(temp->rbit==1)
        {
            temp=temp->right;
        }
        if(temp->rbit==0)
        {
            temp=temp->right;
        }
        
    }
    cout<<endl;
}
void tree::inorder()
{
    node *temp;
    cout<<"Inorder : ";
    temp=head;
    while(1)
    {
        temp=insucc(temp);
        if(temp==head)
        break;
        cout<<temp->data;
    }
    cout<<endl;
    
}
node* tree::insucc(node *temp)
{
    node *t;
    t=temp->right;
    if(temp->rbit==0)
    {

        while(t->lbit==0)
        {
            t=t->left;
        }
    }
    return(t);
    
}
int main()
{
    int ch;
    tree t1;
    while(ch!=4)
    {
        cout<<"\n1:Create\n2:Inorder\n3:Preorder\n4:Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:t1.create();
            break;
            case 2:t1.inorder();
            break;
            case 3:t1.preorder();
            break;
        }   
    }
    
    
    
    return 0;
}
