/*Balaji Gavhane
  Roll no 203248*/
#include<iostream>
using namespace std;
class term
{
	int e;
	double c;
	term *next;
	friend class poly;
};
class poly
{
	term *H;
	public:
	poly();
	void create();
	void display();
    void add(poly p1,poly p2);
    void eval();
    double pow(double x,int n);
};
poly::poly()
{
    H=new term();
    H->e=-1;
    H->next=H;
}
void poly::create()
{
    term *temp;
    char m='y';
    temp=H;
    while(m=='y')
    {
        term *ptr;
        ptr=new term();
        cout<<"Enter coeff:\n";
        cin>>ptr->c;
        cout<<"Enter Exponent:\n";
        cin>>ptr->e;
        temp->next=ptr;
        ptr->next=H;
        temp=ptr;
        cout<<"Want to add another term?\(y/n)\n";
        cin>>m;
    }
}
void poly::display()
{
    term *temp;
    temp=H->next;
    cout<<"Polynomial : ";
    while(temp->e!=-1)
    {
        cout<<temp->c<<"x^"<<temp->e<<"+";
        temp=temp->next;
    }
    cout<<"0\n\n";
}
void poly::add(poly p1,poly p2)
{
    term *t1,*t2,*t3,*temp;
    t1=p1.H->next;
    t2=p2.H->next;
    t3=H;
    temp=new term();
    while(t1->e!=-1 || t2->e!=-1)
    {
        temp=new term();
        if(t1->e<t2->e)
        {
            t3->next=t2;
            t2=t2->next;
            t3=t3->next;
        }
        else if(t1->e>t2->e)
        {
            t3->next=t1;
            t1=t1->next;
            t3=t3->next;
        }
        else
        {

            temp->c=t1->c+t2->c;
            temp->e=t2->e;
            t3->next=temp;
            t2=t2->next;
            t1=t1->next;
            t3=t3->next;
        }
    }
    t3->next=H;
    cout<<"\n\nAddition ";
}
double poly::pow(double x,int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
    {
        p=p*x;
    }
    return p;
}

void poly::eval()
{
    term *temp;
    int x;
    cout<<"Enter the value of x :\n";
    cin>>x;
    double add=0;
    temp=H->next;
    while(temp->e!=-1)
    {
        add=add+temp->c*pow(x,temp->e);
        temp=temp->next;
    }
    cout<<"\nSolution at x = "<<x<<" is "<<add<<endl;
   
}

int main()
{
    int ch;
    poly p1,p2,p3;

    while(ch!=4)
    {
        cout<<"1:Create\n2:Add\n3:Evaluate\n4:Exit\n";

        cin>>ch;
        switch(ch)
        {
            case 1: p1.create();
                    p1.display();
            break;
            case 2:cout<<"Enter 2nd Polynomial\n";
                    p2.create();
                    p2.display();
                    p3.add(p1,p2);
                    p3.display();
            break;
            case 3:p1.create();
                    p1.display();
                    p1.eval();

        }
    }






}
