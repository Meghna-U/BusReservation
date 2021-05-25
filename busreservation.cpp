#include<iostream>
#include<cstdio>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
static int p=0;
class bus1
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i--)
	{
		cout<<ch;
	}
}
void bus1::install()
{
	cout<<"Enter Bus No:";
	cin>>bus[p].busn;
	cout<<"Enter Driver name:";
	cin>>bus[p].driver;
	cout<<"Enter Arrival time:";
	cin>>bus[p].arrival;
	cout<<"Enter Departure time:";
	cin>>bus[p].depart;
	cout<<"From: \t\t";
	cin>>bus[p].from;
	cout<<"To: \t\t";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void bus1::allotment()
{
	int seat;
	char number[5];
	top:
		cout<<"Bus no:";
		cin>>number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		{
			break;
		}
	}
	while(n<=p)
	{
		cout<<"Seat number:";
		cin>>seat;
		if(seat>32)
		{
			cout<<"Sorry! There are only 32 seats available in the bus";
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
			{
				cout<<"Enter passenger's name:";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
			{
				cout<<"Seat number is already reserved.";
			}
		}
		if(n>p)
		{
			cout<<"\nEnter correct bus number:";
			goto top;
		}
	}
}
void bus1::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"Empty");
		}
	}
}
void bus1::show()
{
	int n;
	char number[5];
	cout<<"Enter Bus no:";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"\nBus no: "<<bus[n].busn<<endl;
		cout<<"Driver Name: "<<bus[n].driver<<endl;
		cout<<"Arrival time: "<<bus[n].arrival<<endl;
		cout<<"Departure time: "<<bus[n].depart<<endl;
		cout<<"From: "<<bus[n].from<<endl;
		cout<<"To: "<<bus[n].to<<endl;
		vline('*');
		bus[0].position(n);
		int a=1;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
				{
					cout<<"\nThe seat number "<<a-1<<" is reserved for "<<bus[n].seat[i][j];
				}
			}
		}
		break;
	}
	if(n>p)
	{
		cout<<"Enter correct bus number:";
	}
}
void bus1::position(int k)
{
	int s=0;p=0;
	for(int i=0;i<8;i++)
	{
		cout<<endl;
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[k].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[k].seat[i][j];
				p++;
			}
			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[k].seat[i][j];
			}
		}
	}
	cout<<"There are "<<p<<"empty seats in the bus number "<<bus[k].busn;
}
void bus1::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"Bus No:"<<bus[n].busn<<endl;
		cout<<"Driver name:"<<bus[n].driver<<endl;
		cout<<"Arrival time:"<<bus[n].arrival<<endl;
		cout<<"Departure time:"<<bus[n].depart<<endl;
		cout<<"From:"<<bus[n].from<<endl;
		cout<<"To:"<<bus[n].to<<endl;
		vline('*');
		vline('_');
	}
}
int main()
{
	system("cls");
	int c;
	while(1)
	{
		cout<<"\n1.Install\n2.Reservation\n3.Show\n4.Buses available\n5.Exit\nChoose an option:";
		cin>>c;
		switch(c)
	    {    
		case 1:bus[p].install();
		break;
		case 2:bus[p].allotment();
		break;
		case 3:bus[0].show();
		break;
		case 4:bus[0].avail();
		break;
		case 5:exit(0);
		break;
	    }
	}
   return 0;
}
