#include<iostream>
#include<iomanip>
using namespace std;
void getdata(int [][2],int [][2], int);
void printdata(int [][2],int);
void dataselection(int ,int [][2],int,int [][10]);
int getmax(int [][2],int);
void printtable(int ,int [][10],int,int [][2]);
int class_per_day(int [][2],int);
int main()
{
	int total_subjects,total_classes;
	cout<<"Enter the total Number of Subjects\n";
	cin>>total_subjects;
	cout<<"Enter total classes per day\n";
	cin>>total_classes;
	int data[total_subjects][2],data_copy[total_subjects][2];
	getdata(data,data_copy,total_subjects);
	printdata(data,total_subjects);
	int temp[total_classes][10];
	dataselection(total_classes,data_copy,total_subjects,temp);
	printtable(total_classes,temp,total_subjects,data);
	return 0;
}
void getdata(int data[][2],int data_copy[][2],int total_subjects)
{
	int i;
	for(i=0;i<total_subjects;i++)
	{
		cout<<"Enter the subject code for subject "<<i+1<<endl;
		cin>>data[i][0];
		data_copy[i][0]=data[i][0];
		cout<<"Enter the subject credits for subject "<<i+1<<endl;
        cin>>data[i][1];
		data_copy[i][1]=data[i][1];
	}
}
void printdata(int data[][2],int total_subjects)
{       
	int i;
	cout<<"\tSUBJECTS_CODE\tSUBJECT_CREDIT\n";
        for(i=0;i<total_subjects;i++)
        {       
                cout<<setw(14)<<data[i][0]<<setw(16)<<data[i][1]<<endl;
        }
}

void dataselection(int total_classes,int data_copy[][2],int total_subjects,int temp[][10])
{
	int i,j,pos;
	for(i=0;i<class_per_day(data_copy,total_subjects);i++)
	{
		for(j=0;j<=6;j++)
		{
			pos=getmax(data_copy,total_subjects);
			if(pos==-1){
				temp[i][j]=0;
			}
			else	
			temp[i][j]=data_copy[pos][0];
		}
	}
			
}
int getmax(int data_copy[][2],int total_subjects)
{
	int i,high,pos;
	high=data_copy[0][1];
	for(i=1;i<total_subjects;i++)
	{
		if(data_copy[i][1]>high)
		{
			high=data_copy[i][1];
			pos=i;
		}
	}
	data_copy[pos][1]-=1;
	if(high==0){
		pos=-1;
	}
	return pos;
}

void printtable(int total_classes,int temp[][10],int total_subjects,int data[][2])
{
        int i,j;
	cout<<"\t\t\t\t\tTIME TABLE\n";
        cout<<"\t\tMONDAY   TUESDAY  WEDNESDAY   THURSDAY  FRIDAY   SATURDAY\n";
        for(i=0;i<class_per_day(data,total_subjects);i++)
	{
		cout<<"Period : "<<i+1;
		for(j=0;j<6;j++)
       		{
               		cout<<setw(10)<<temp[i][j];

        	}
		cout<<endl;
	}
}

int class_per_day(int data_copy[][2],int total_subjects){
	int i,m=0;
	for(i=0;i<total_subjects;i++)
		m+=data_copy[i][1];
	m=(m/6)+1;
	return m;
}