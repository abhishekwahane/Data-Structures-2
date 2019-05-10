/*Balaji Gavhane
  Roll no 203248 */
#include<iostream>
using namespace std;
class node
{
    public:
    int marks;
    string name;
    
    node()
    {
        marks=0;
        name="";
    }
};
class heap
{
    node a[30];
    public:
    void create();
    void insert(node a[30],int index,int f);
    void display();
    void heapsort();
};
void heap::create()
{
    int i,j=1,f;
    char ch;
    cout<<"\nWhich heap to you want to create\n1:Max Heap\n2:Min Heap\n?";
    cin>>f;
    do
    {
        cout<<"\nEnter name : ";
        cin>>a[j].name;
        cout<<"\nEnter Marks : ";
        cin>>a[j].marks;
        insert(a,j,f);
        j++;
        cout<<"\nDo you want to add another student details?(y/n)";
        cin>>ch;
    }
    while(ch=='y');
    if(f==1)
    {
        cout<<"\nMax Marks : "<<a[1].marks<<endl;
        cout<<"\nName : "<<a[1].name;
    }
    else
    if(f==2)
    {
        cout<<"\nMin Marks : "<<a[1].marks<<endl;
        cout<<"\nName : "<<a[1].name<<endl;
    }
}
void heap::insert(node a[30],int index,int f)
{
    int i;
    node temp;
    i=index;
    temp=a[i];
    if(f==1)
    {
        while(i>1 && a[i/2].marks<temp.marks)
        {
            a[i]=a[i/2];
            i=i/2;
        }
        a[i]=temp;
    }
    else if(f==2)
    {
        while(i>1 && a[i/2].marks>temp.marks)
        {
            a[i]=a[i/2];
            i=i/2;
        }
        a[i]=temp;
    }
    
}

int main()
{
    heap h1;
    h1.create();
    return 0;
}