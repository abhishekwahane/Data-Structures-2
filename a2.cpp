/*Balaji Gavhane
  Roll no 203248 */
#include<iostream>
using namespace std;
class node
{
	char d[20];
	node *left;
	node *right;
    friend class tree;
    friend class stack;
};
class tree
{
    node *root;
    public:
    tree();
    void create();
    void preorder(node *root);
    void preorder1();
    void postorder();
    void postorder1(node *root);
    void inorder();
    void inorder1(node *root);
    void creater();
    void createtr(node *root);
    void prenr();
    void postnr();
    void inr();
    void erase();
    void postorder1er(node *root);
};
class stack
{
    int top;
    node *data[20];
    public:
    stack();
    void push(node *p);
    node* pop();
    int stackempty()
    {
        if(top==-1)
        return 1;
        else
        return 0;
    }
    friend class tree;
};
stack::stack()
{
    top=-1;
}
void stack::push(node *p)
{
    if(top!=19)
    {
        top++;
        data[top]=p;
    }
    
}
node* stack::pop()
{
    node *temp;

    if(stackempty()==0)
    {
        temp=data[top];
        top--;
        return temp;
    }
}
void tree::creater()
{
    if(root==NULL)
    {
        root=new node();
        cout<<"Enter data:\n";
        cin>>root->d;
        root->left=root->right=NULL;

        createtr(root);
    }
}
void tree::createtr(node *root)
{
    node *curr;
    char ch,c;
    cout<<"Do you want to add node on left of "<<root->d<<"(y/n)"<<endl;
    cin>>ch;
    if(ch=='y')
    {
        curr=new node();
        cout<<"Enter data:\n";
        cin>>curr->d;
        curr->left=curr->right=NULL;
        if(root->left==NULL)
        {
            root->left=curr;
        }
        createtr(root->left);
    }
    cout<<"Do you want to add node on right of "<<root->d<<"(y/n)"<<endl;
    cin>>c;
    if(c=='y')
    {
        curr=new node();
        cout<<"Enter data:\n";
        cin>>curr->d;
        curr->left=curr->right=NULL;
        if(root->right==NULL)
        {
            root->right=curr;
        }
        createtr(root->right);
    }
}
tree::tree()
{
    root=NULL;
}
void tree::preorder1()
{
    preorder(root);
    cout<<endl;
}
void tree::inr()
{
	node *temp;
    temp=new node();
    stack s1;
    temp=root;
    cout<<"\nInorder:";
    while(1)
    {
        while(temp!=NULL)
        {
            s1.push(temp);
            temp=temp->left;
        }
        if(s1.stackempty()==1)
        break;
        temp=s1.pop();
        cout<<temp->d;
        temp=temp->right;
    }
    cout<<endl;
}
void tree::prenr()
{
	node *temp,*flag;
    temp=new node();
    stack s1;
    temp=root;
    cout<<"\nPreorder:";
    while(1)
    {
        while(temp!=NULL)
        {
            cout<<temp->d;
            s1.push(temp);
            temp=temp->left;
        }
        if(s1.stackempty()==1)
        break;
        temp=s1.pop();
        temp=temp->right;
    }
    cout<<endl;
}
void tree::postnr()
{
    stack s1;
    node *temp;
    temp=new node;
    temp=root;
    cout<<"Postorder:";
    while(1)
    {
        while(temp!=NULL)
        {
            s1.push(temp);
            temp=temp->left;
        }
        if(s1.data[s1.top]->right==NULL)
        {
            temp=s1.pop();
            cout<<temp->d;
        }
        while(s1.stackempty()==0 && s1.data[s1.top]->right==temp)
        {
            temp=s1.pop();
            cout<<temp->d;
        }
        if(s1.stackempty()==1)
        break;
        temp=s1.data[s1.top]->right;
    }
    cout<<endl;
}
void tree::erase()
{
   postorder1er(root);

}

void tree::create()
{
    node *temp,*curr;
    char ch,c;
    int flag=0;
    do
    {
        if(root==NULL)
        {
            root=new node();
            cout<<"Enter data\n";
            cin>>root->d;
            root->left=root->right=NULL;
        }
        else
        {
            temp=root;
            curr=new node();
            cout<<"Enter data\n";
            cin>>curr->d;
            curr->left=curr->right=NULL;
            while(flag==0)
            {
                cout<<"Do you want to add to "<<temp->d<<"'s left or right?(l/r)"<<endl;
                cin>>ch;
                if(ch=='l')
                {
                    if(temp->left==NULL)
                    {
                        temp->left=curr;
                        flag=1;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else if(ch=='r')
                {
                    if(temp->right==NULL)
                    {
                        temp->right=curr;
                        flag=1;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }
            }
            flag=0;
        }
        cout<<"Do you want to continue?(y/n)"<<endl;
        cin>>c;
    }
    while(c=='y');
}
void tree::preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->d;

    preorder(root->left);
    preorder(root->right);
    }
}
void tree::postorder1(node *root)
{
    if(root!=NULL)
    {
        postorder1(root->left);
        postorder1(root->right);
        cout<<root->d;
    }
}
void tree::postorder1er(node *root)
{
    node *temp;
    if(root!=NULL)
    {
        postorder1(root->left);
        postorder1(root->right);
	temp=root;
        delete(temp);
    }
}
void tree::inorder()
{
    inorder1(root);
    cout<<endl;
}
void tree::inorder1(node *root)
{
    if(root!=NULL)
    {
        inorder1(root->left);
        cout<<root->d;
        inorder1(root->right);
    }
}

void tree::postorder()
{
    postorder1(root);
    cout<<endl;
}

int main()
{
    int ch;
    while(ch!=6)
    {
        cout<<"1:Non recurse create\n2:Recurse create\n3:Display Recursive\n4:Display Non Recursive\n5:Erase\n6:Exit\n";
        cin>>ch;
        tree t1;
        switch(ch)
        {
            case 1:t1.create();
                    cout<<"Preorder:";
                    t1.preorder1();
                    cout<<"Postorder:";
                    t1.postorder();
                    cout<<"Inorder:";
                    t1.inorder();
                    break;
            case 2:t1.creater();
                    cout<<"Preorder:";
                    t1.preorder1();
                    cout<<"Postorder:";
                    t1.postorder();
                    cout<<"Inorder:";
                    t1.inorder();
            break;
            case 3:cout<<"Preorder:";
                    t1.preorder1();
                    cout<<"Postorder:";
                    t1.postorder();
                    cout<<"Inorder:";
                    t1.inorder();
                    break;
            case 4:t1.create();
                    t1.inr();
                    t1.prenr();
                    t1.postnr();
                    break;
            case 5:t1.erase();
                    cout<<"\nData erased\n";
                    
        }
    }
}
