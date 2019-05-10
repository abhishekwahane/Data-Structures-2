/*Balaji Gavhane
  Roll no 203248
  Batch B1   */
#include<iostream>
using namespace std;
class node
{
	string w,m;
	node *left;
	node *right;
    friend class tree;
    friend class queue;
    friend class stack;
};
class queue
{
    node *d[20];
    int front,rear;
    public:
    void insert(node *temp);
    node* del();
    queue();
    int qempty();
    friend class tree;
};
class stack
{
    int top;
    node *d[20];
    public:
    void push(node *p);
    node *pop();
    int stempty();
    stack();
    friend class tree;
};
class tree
{
    node *root;
    public:
    tree();
    node* getroot();
    //create
    void create();
    void creater();
    void rcreate(node *root,node *curr);
    //display
    void preorder(node *root);
    void preorder1();
    void postorder();
    void postorder1(node *root);
    void inorder();
    void inorder1(node *root);
    //height
    void ht();   
    int hght(node *root);
    //Breath first display
    void bfs();
    //search
    void search();
    //copy
    void copy(node *root);
    //erase
    void erase();
    void erase1(node *root);
    //mirror
    void mirror();
    void mr(node *root);
    //delete
    void Delete();
};
void tree::mirror()
{
    mr(root);
}
void tree::mr(node *root)
{
    node *temp;
    if(root!=NULL)
    {
        mr(root->left);
        mr(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}
stack::stack()
{
    top=-1;
}
void stack::push(node *p)
{
    top++;
    d[top]=p;
}
node* stack::pop()
{
    node *temp;
    if(stempty()==0)
    return NULL;
    else
    {
        temp=d[top];
        top--;
        return temp;
    }
}
int stack::stempty()
{
    if(top==-1)
    return 0;
    else
    return 1;
}

void tree::Delete()
{
    string key;
    int flag=0;
    cout<<"Enter the word to delete:\n";
    cin>>key;
    node *temp,*p,*s,*t1;
    p=NULL;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->w==key)
        {
            if(p==NULL)
            {
                if(temp->left==NULL && temp->right==NULL)
                delete(temp);
                else if(temp->left!=NULL && temp->right==NULL)
                {
                    root=temp->left;
                    temp->left=temp->right=NULL;
                    delete(temp);
                }
                else if(temp->left==NULL && temp->right!=NULL)
                {
                    root=temp->right;
                    temp->left=temp->right=NULL;
                    delete(temp);
                }
                else if(temp->left!=NULL && temp->right!=NULL)
                {
                    t1=temp->left;
                    root=temp->right;
                    s=temp->right;
                    while(s->left!=NULL)
                    {
                        s=s->left;
                    }
                    s->left=t1;
                    temp->left=temp->right=NULL;
                    delete(temp);
                }
            }
            else
            {
                if(temp->left==NULL && temp->right==NULL)
                {
                    delete(temp);
                    if(temp==p->left)
                    {
                        p->left=NULL;
                    }
                    else
                    p->right=NULL;
                }
                else if(temp->left!=NULL && temp->right==NULL)
                {
                    if(temp==p->left)
                    {
                        p->left=temp->left;
                    }
                    else
                    p->right=temp->left;
                    temp->left=temp->right=NULL;
                    delete(temp);
                }
                else if(temp->left==NULL && temp->right!=NULL)
                {
                    if(temp==p->left)
                    {
                        p->left=temp->right;
                    }
                    else
                    p->right=temp->right;
                    temp->left=temp->right=NULL;
                    delete(temp);
                }
                else if(temp->left!=NULL && temp->right!=NULL)
                {

                    t1=temp->left;
                    if(temp==p->left)
                    {
                        p->left=temp->right;
                    }
                    else
                    p->right=temp->right;
                    s=temp->right;
                    while(s->left!=NULL)
                    {
                        s=s->left;
                    }
                    temp->left=temp->right=NULL;
                    s->left=t1;
                    delete(temp);
                }
            }
            flag=1;
            cout<<"\nNode Deleted!\n\n";
            break;
        }
        else if(key>temp->w)
        {
            p=temp;
            temp=temp->right;
        }
        else if(key<temp->w)
        {
            p=temp;
            temp=temp->left;
        }
    }
    if(flag==0)
    cout<<"\nKey not found!!\n";
}
/*void tree::mirror()
{
    stack s1;
    node *temp,*l,*r,*f;
    temp=root;
    while(1)
    {
        while(temp!=NULL)
        {
            s1.push(temp);
            temp=temp->left;
        }
        if(s1.stempty()==0)
        break;
        temp=s1.pop();
        l=temp->left;
        r=temp->right;
        f=l;
        l=r;
        r=f;
        temp=temp->left;
    }
}*/
node* tree::getroot()
{
    return root;
}
void tree::copy(node *temp)
{
    root=temp;
}
void tree::erase()
{
    erase1(root);
}
void tree::erase1(node *root)
{
    if(root!=NULL)
    {
        erase1(root->left);
        erase1(root->right);
        root->w=root->m="";
        delete(root);
    }
}

queue::queue()
{
    front=-1;
    rear=-1;
}
void queue::insert(node *temp)
{
    rear++;
    d[rear]=temp;
}
node* queue::del()
{
    front++;
    return d[front];
}
int queue::qempty()
{
    if(front==rear)
    return 0;
    else
    return 1;
}
void tree::create()
{
    node *curr,*temp;
    char ch;
    int flag=0;
    do
    {
        if(root==NULL)
        {

            root=new node();
            cout<<"Enter Word:\n";
            cin>>root->w;
             cout<<"Enter Meaning:\n";
            cin>>root->m;
            root->left=root->right=NULL;
        }
        else
        {
            temp=root;
            curr=new node();
            cout<<"Enter Word:\n";
            cin>>curr->w;
            cout<<"Enter Meaning:\n";
            cin>>curr->m;
            curr->left=curr->right=NULL;
            while(flag==0)
            {
                if(curr->w>temp->w)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=curr;
                        flag=1;
                    }
                    else
                    temp=temp->right;
                }
                else if(curr->w<temp->w)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=curr;
                        flag=1;
                    }
                    else
                    temp=temp->left;
                }
            }
            
        }       
        cout<<"Do you want to add another node?(y/n)\n";
        cin>>ch;
        flag=0;
    }
    while(ch=='y');
}
void tree::creater()
{
    char ch;
    node *curr;
    do
    {
        if(root==NULL)
        {
            root=new node();
            cout<<"Enter Word:\n";
            cin>>root->w;
            cout<<"Enter Meaning:\n";
            cin>>root->m;
            root->left=root->right=NULL;
        }
        else
        {
            curr=new node();
            cout<<"Enter Word:\n";
            cin>>curr->w;
            cout<<"Enter Meaning:\n";
            cin>>curr->m;
            rcreate(root,curr);
        }
        cout<<"Do you want to add another node?(y/n)\n";
        cin>>ch;
    }
    while(ch=='y');
    
}
void tree::rcreate(node *root,node *curr)
{
    if(curr->w > root->w)
    {
        if(root->right==NULL)
        root->right=curr;
        else
        rcreate(root->right,curr);
    }
    else if(curr->w < root->w)
    {
        if(root->left==NULL)
        root->left=curr;
        else
        rcreate(root->left,curr);
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
void tree::preorder(node *root)
{
    if(root!=NULL && root->w!="")
    {
        cout<<root->w<<" : "<<root->m<<endl;

    preorder(root->left);
    preorder(root->right);
    }
}
void tree::postorder()
{
    postorder1(root);
    cout<<endl;
}
void tree::postorder1(node *root)
{
    if(root!=NULL && root->w!="")
    {
        postorder1(root->left);
        postorder1(root->right);
        cout<<root->w<<" : "<<root->m<<endl;
    }
}
void tree::inorder()
{
    inorder1(root);
    cout<<endl;
}
void tree::inorder1(node *root)
{
    if(root!=NULL && root->w!="")
    {
        inorder1(root->left);
        cout<<root->w<<" : "<<root->m<<endl;
        inorder1(root->right);
    }
}

void tree::ht()
{
    int h;
    h=hght(root);
    cout<<"Height : "<<h<<endl;
}
int tree::hght(node *root)
{
    int t1,t2;
    if(root==NULL)
    return 0;
    else
    {
        t1=hght(root->left)+1;
        t2=hght(root->right)+1;
        if(t1>t2)
        return t1;
        else
        return t2;
   }
}
void tree::bfs()
{
    queue q;
    node *temp;
    temp=root;
    q.insert(temp);
    cout<<"Breath first traversal display :\n ";
    while(q.qempty()==1)
    {
        temp=q.del();
        cout<<temp->w<<" : "<<root->m<<endl;
        if(temp->left!=NULL)
        q.insert(temp->left);
        if(temp->right!=NULL)
        q.insert(temp->right);
    }
    cout<<endl;
}
void tree::search()
{
    int flag=0;
    string key;
    cout<<"Enter the key to search:\n";
    cin>>key;
    node *temp;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->w==key)
        {
            cout<<"\nKey found!!\n";
            flag=1;
            break;
        }
        else if(key>temp->w)
        temp=temp->right;
        else if(key<temp->w)
        temp=temp->left;
    }
    if(flag==0)
    cout<<"\nKey not found!!\n";
}
int main()
{
    int ch;
    tree t1,t2;
    node *temp;
    while(ch!=11)
    {
        cout<<"\n1:Non recurse create\n2:Recurse create\n3:Display\n4:Height\n5:BFS Display\n6:Search\n7:Delete\n8:Copy\n9:Mirror Image\n10:Erase\n11:Exit\n";
        cin>>ch;
        
        switch(ch)
        {
            case 1:t1.create();
                    cout<<"\nPreorder : \n";
                    t1.preorder1();
                    cout<<"Postorder : \n";
                    t1.postorder();
                    cout<<"Inorder : \n";
                    t1.inorder();
                    break;
            case 2:t1.creater();
                    cout<<"\nPreorder : \n";
                    t1.preorder1();
                    cout<<"Postorder :\n ";
                    t1.postorder();
                    cout<<"Inorder : \n";
                    t1.inorder();
            break;
            case 3: cout<<"\nPreorder : \n";
                    t1.preorder1();
                    cout<<"Postorder : \n";
                    t1.postorder();
                    cout<<"Inorder : \n";
                    t1.inorder();
                    break;
            case 4:t1.ht();
                    break;
            case 5:t1.bfs();
                    break;
            case 6:t1.search();
                    break;
            case 7:t1.Delete();
                    cout<<"\nPreorder : \n";
                    t1.preorder1();
                    cout<<"Postorder : \n";
                    t1.postorder();
                    cout<<"Inorder : \n";
                    t1.inorder();
                    break;
            case 8:temp=t1.getroot();
                    t2.copy(temp);
                    cout<<"\nPreorder : \n";
                    t2.preorder1();
                    cout<<"Postorder : \n";
                    t2.postorder();
                    cout<<"Inorder : \n";
                    t2.inorder();
                    break;
            case 9:t1.mirror();
                    cout<<"\nMirror Image : \n";
                    cout<<"\nPreorder : \n";
                    t1.preorder1();
                    cout<<"Postorder : \n";
                    t1.postorder();
                    cout<<"Inorder : \n";
                    t1.inorder();
            case 10:t1.erase();
                    cout<<"\nData erased\n";
                    break;
        }
    }
}
