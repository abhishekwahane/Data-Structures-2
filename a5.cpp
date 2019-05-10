/*Balaji Gavhane
  Roll No 203248
  Panel 2
  Batch B1   */
#include<iostream>
using namespace std;
class node
{
    string uname;
    node *next;
    friend class graph;
};
class graph
{
    int n;
    node *head[20];
    int visited[20];
    public:
    graph()
    {
        int i;
        for(i=0;i<20;i++)
        {
            head[i]=NULL;
        }
    }
    void create();
    void display();
    int search(node *temp);
    void dfs();
    void dfsr(int temp);
    void bfs();
    void dfsnon();
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
    friend class graph;
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
    friend class graph;
};
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
void graph::create()
{
    node *temp,*curr,*temp1;
    int i=0;
    char ch;
    cout<<"\nEnter the no of users : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        head[i]=new node();
        cout<<"\nEnter username : ";
        cin>>head[i]->uname;
    }
    for(i=0;i<n;i++)
    {
        temp=head[i];
        temp1=head[i];
        do
        {
            cout<<"\nEnter the username of friend of "<<temp1->uname<<" : ";
            curr=new node();
            cin>>curr->uname;
            curr->next=NULL;
            temp->next=curr;
            cout<<"\nDoes "<<temp1->uname<<" have more friends? (y/n)";
            cin>>ch;
            temp=temp->next;
        }
        while(ch=='y');
    }
}
int graph::search(node *temp)
{
    int i,index;
    for(i=0;i<n;i++)
    {
        if(head[i]->uname==temp->uname)
        {
            return i;    
            
        }        
    }
}
void graph::dfs()
{
    node *v;
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    v=new node();
    cout<<"\nEnter the starting node username : ";
    cin>>v->uname;
    int index=search(v);
    cout<<"\nDFS Display : ";
    dfsr(index);
}
void graph::dfsr(int temp)
{
    node *t;
    visited[temp]=1;
    t=head[temp];
    cout<<t->uname<<" ";
    
    while(t!=NULL)
    {
        int index=search(t);
        if(visited[index]==0)
        dfsr(index);
        t=t->next;
    }
    
    
}
void graph::display()
{
    node *temp;
    int i;
    for(i=0;i<n;i++)
    {
        temp=head[i];
        cout<<"\nFriends of "<<temp->uname<<" : ";
        while(temp!=NULL)
        {
            temp=temp->next;
            if(temp!=NULL)
            cout<<temp->uname<<" ";
        }
    }
    cout<<endl;
}
void graph::bfs()
{
   node *t;
   int i,index;
   t=new node();
   cout<<"\nEnter the name of starting User : ";
   cin>>t->uname;
   cout<<"\nBFS Display : ";
   for(i=0;i<n;i++)
   {visited[i]=0;}
   index=search(t); 
   t=head[index];
   queue q;
   q.insert(t);
   visited[index]=1;
   while(q.qempty()==1)
   {
        t=q.del();
        cout<<t->uname<<" ";
        index=search(t); 
        t=head[index]->next;
        while(t!=NULL)
        {
            index=search(t);
            if(visited[index]==0)
            {
                q.insert(t); 
                visited[index]=1;
            }
            t=t->next;
        } 
    }
    cout<<endl<<endl;
}
void graph::dfsnon()
{
    node *t;
   int i,index;
   t=new node();
   cout<<"\nEnter the name of starting User : ";
   cin>>t->uname;
   cout<<"\nDFS(Non Recursive) Display : ";
   for(i=0;i<n;i++)
   {visited[i]=0;}
   index=search(t); 
   t=head[index];
   stack q;
   q.push(t);
   visited[index]=1;
   while(q.stempty()==1)
   {
        t=q.pop();
        cout<<t->uname<<" ";
        index=search(t); 
        t=head[index]->next;
        while(t!=NULL)
        {
            index=search(t);
            if(visited[index]==0)
            {
                q.push(t); 
                visited[index]=1;
            }
            t=t->next;
        } 
    }
    cout<<endl<<endl;
}
int main()
{
    int ch;
    graph g1;
    while(ch!=5)
    {
        cout<<"\n\n1:Create\n2:DFS(Recursive)\n3:DFS(Non Recursive)\n4:BFS\n5:Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:g1.create();
                    g1.display();
            break;
            case 2: g1.dfs();
            break;
            case 3:g1.dfsnon();
            break;
            case 4:g1.bfs();
        }
    }
    return 0;
    
   
    
    
}
