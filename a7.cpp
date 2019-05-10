/*Balaji Gavhane
  Roll No 203248 */
#include<iostream>
using namespace std;
class hash
{
	public:
	int data,visited,marks;
	string name;
	hash()
	{
		data=-1;
		visited=0;
		name="-";
		marks=-1;
	}
};
void storenr(hash h[10])
{
	int d,flag=0,i,loc;
	//hash h[10];
	char ch;
	do
	{
		cout<<"\nEnter the Student details : ";
		cout<<"\n\nRoll no : ";
		cin>>d;
		if(h[d%10].visited==0)
		{
			h[d%10].data=d;
			
			cout<<"\nName : ";
			cin>>h[d%10].name;
			cout<<"\nMarks : ";
			cin>>h[d%10].marks;
			cout<<"\n\nData Stored!";
			h[d%10].visited=1;

		}
		else
		{
			for(i=(d%10)+1;i!=(d%10);i=(i+1)%10)
			{
				if(h[i].visited==0)
				{
					h[i].data=d;
					h[i].visited=1;
					cout<<"\nName : ";
					cin>>h[i].name;
					cout<<"\nMarks : ";
					cin>>h[i].marks;
					cout<<"\nData Stored!";
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nInsufficient Space!";
				break;
			}
			
		}
		cout<<"\n\nDo you want to add more data ?(y/n)";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}
void storewithrep(hash h[10])
{
	int d,flag=0,i,temp;
	//hash h[10];
	char ch;
	do
	{
		cout<<"\nEnter the Student details : ";
		cout<<"\n\nRoll no : ";
		cin>>d;

		if(h[d%10].visited==0)
		{
			h[d%10].data=d;
			h[d%10].visited=1;
			cout<<"\nName : ";
			cin>>h[d%10].name;
			cout<<"\nMarks : ";
			cin>>h[d%10].marks;
			cout<<"\n\nData Stored!";
		}
		else if(h[d%10].visited==1 && h[d%10].data%10!=d%10)
		{
			hash temp;
			temp=h[d%10];
			h[d%10].data=d;
			cout<<"\nName : ";
			cin>>h[d%10].name;
			cout<<"\nMarks : ";
			cin>>h[d%10].marks;
			cout<<"\nData Stored!";
			for(i=(d%10)+1;i!=(d%10);i=(i+1)%10)
			{
				if(h[i].visited==0)
				{
					h[i]=temp;
					h[i].visited=1;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nInsufficient Space!";
				break;
			}
		}
		else
		{
			for(i=(d%10)+1;i!=(d%10);i=(i+1)%10)
			{
				if(h[i].visited==0)
				{
					h[i].data=d;
					h[i].visited=1;
					cout<<"\nName : ";
					cin>>h[i].name;
					cout<<"\nMarks : ";
					cin>>h[i].marks;
					cout<<"\nData Stored!";
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nInsufficient Space!";
				break;
			}
			
		}
		cout<<"\n\nDo you want to add more data ?(y/n)";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');	
}
void display(hash h[10])
{
	int i;
	cout<<"\n\nStorage Representation : ";
	cout<<"\n\nIndex\tRollNo\tName\tMarks\n\n";
	for(i=0;i<10;i++)
	{
		if(h[i].data!=-1)
		cout<<i<<"\t"<<h[i].data<<"\t"<<h[i].name<<"\t"<<h[i].marks<<"\n";
	}
	cout<<endl;
}
void search(hash h[10])
{
	int key,i,flag=0;
	cout<<"\nEnter the Roll no. to search : ";
	cin>>key;
	if(h[key%10].data==key)
	{
		cout<<"\nRecord Found!\n";
		cout<<"\nName : "<<h[key%10].name;
		cout<<"\nRoll No : "<<h[key%10].data;
		cout<<"\nMarks : "<<h[key%10].marks<<endl;
	}
	else
	{
		for(i=(key%10)+1;i!=(key%10);i=(i+1)%10)
			{
				if(h[i].data==key)
				{
					cout<<"\nRecord Found!\n";
					cout<<"\nName : "<<h[i].name;
					cout<<"\nRoll No : "<<h[i].data;
					cout<<"\nMarks : "<<h[i].marks<<endl;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"\nRecord not found\n";
				
			}
	}
	
	
	
}
int main()
{
	int ch;
	hash h[10];
	while(ch!=3)
	{
		cout<<"\n\n1:Hashing with Replacement\n2:Hashing without Replacement\n3:Search\n4:Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:storewithrep(h);
					display(h);
			break;
			case 2:storenr(h);
					display(h);
			break;
			case 3:search(h);
			break;
		}
	}
	
	
}
