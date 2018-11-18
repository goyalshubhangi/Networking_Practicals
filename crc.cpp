#include<iostream>
using namespace std;
int main()
{
	int fs,g,j,k;
	cout<<"Enter the size of frame: ";
    cin>>fs;
    int frame[20];
    cout<<"Enter the frame in either 1 or 0\n";
    for(int i=0;i<fs;i++)
    {
    	cin>>frame[i];
    }
    cout<<"Enter the size of generator function: ";
    cin>>g;
    int gen[20];
    cout<<"Enter the generator function:\n";
    for(int i=0;i<g;i++)
    {
    	cin>>gen[i];
    }
    cout<<"SENDERS SIDE\n";
    cout<<"Frame\n";
    for(int i=0;i<fs;i++)
    {
    	cout<<frame[i];
    }
    cout<<"\nGenerator function:\n";
    for(int i=0;i<g;i++)
    {
    	cout<<gen[i];
    }
    cout<<"\n";
//numberof zeroes to be appended in frame 
    int zer=g-1;
    for(int i=fs;i<=fs+zer;i++)
    {
    	frame[i]=0;
    }
    int temp[20];
    for(int i=0;i<20;i++)
    {
    	temp[i]=frame[i];
    }
    cout<<"\nMessage after appending zeroes:";
    for(int i=0;i<fs+zer;i++)
    {
    	cout<<temp[i];
    }
    cout<<"\n";











    //Division
    for( int i=0;i<fs;i++)
    {
		j=0;
		k=i;
		if(temp[k]>=gen[j])
		{
		for(j=0,k=i;j<g;j++,k++)
		{
			if((temp[k]==1 && gen[j]==1) || (temp[k]==0 && gen[j]==0 ))
				{
					temp[k]=0;
				}
				else
				{
					temp[k]=1;
				}
				}
		}
    }
     int crc[15];
     for( int i=0,j=fs;i<zer;i++,j++)
     {
     	crc[i]=temp[j];
     }
     cout<<"\nCRC bits\n";
     for (int i = 0; i < zer; ++i)
     {
     	cout<<crc[i];
     }
cout<<"\nTransmitted Frame\n";
int tf[15];
for(int i=0;i<fs;i++)
{
	tf[i]=frame[i];
}
for(int i=fs,j=0;i<fs+zer;i++,j++)
{
	
		tf[i]=crc[j];
	
}
for(int i=0;i<fs+zer;i++)
{
	cout<<tf[i];
}

cout<<"Receivers side";
cout<<"Rerceived Frame: ";
for(int i=0;i<fs+zer;i++)
{
	cout<<tf[i];
}

for(int i=0;i<fs+zer;i++)
{
	temp[i]=tf[i];
}
//Division
for(int i=0;i<fs+zer;i++)
{
j=0;
k=i;
if(temp[k]>=gen[j])
{
	for(j=0,k=i;j<g;j++,k++)
	{
		if((temp[k]==1 && gen[j]==1) || (temp[k]==0 && gen[j]==0 ))
				{
					temp[k]=0;
				}
				else
				{
					temp[k]=1;
				}
				
	}
}
}
cout<<"Remainder: ";
int rem[15];
for(int i=fs,j=0;i<fs+zer;i++,j++)
{
	rem[j]=temp[i];
}
for(int i=0;i<zer;i++)
{
	cout<<rem[i];
}
int flag=0;
for(int i=0;i<zer;i++)
{
	if(rem[i]!=0)
	{
		flag=1;
	}
}
if(flag==0)
{
	cout<<"Transfered successfully";

}
else
{
	cout<<"Error";
}
}