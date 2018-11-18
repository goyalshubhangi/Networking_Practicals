#include<iostream>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
int main()
{
	int noframes,x1=10,b=1;
	noframes=rand()%100;
	noframes=noframes/8;
	cout<<"Number of Frames to be send: "<<noframes;
	while(noframes>0)
	{
		cout<<"\n\nSENDING FRAMES\n\n";
		int x= rand()%10;
		if(x%2==0)
		{
			for(int x2=1;x2<2;x2++)
			{
				cout<<"\n\nWaiting for "<<x2<<"seconds\n\n";
				sleep(x2);
			}
	}
	cout<<"\n\nAck received for "<<b<<"\n\n";
	noframes=noframes-1;
	b++;
	}
	cout<<"\nEnd stop and wait protocol.........\n";
}