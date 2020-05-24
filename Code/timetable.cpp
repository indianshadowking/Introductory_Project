 #include<iostream>
#include<iomanip>
using namespace std;
void getdata(int [][2],int [][2], int);
void printdata(int [][2],int);
void dataselection(int [][2],int,int [][10]);
int getmax(int [][2],int);
void printtable(int [][10],int,int [][2],int);
int class_per_day(int [][2],int);
void repeat_same_hour(int [][10],int [][2],int);
int repeat_same_hour_check(int [][10],int [][2], int );
void repeat_same_day(int [][10],int [][2],int);
int repeat_same_day_check(int [][10],int [][2], int );
int cost_compute(int [10][10],int,int [][2]);
void copy(int, int [10][10], int [][10][10],int);
int main()
{
	int total_subjects,n=0,min,pos;
	cout<<"Enter the total Number of Subjects\n";
	cin>>total_subjects;
	int data[total_subjects][2],data_copy[total_subjects][2],i,J_hist[100];
	getdata(data,data_copy,total_subjects);
	printdata(data,total_subjects);
	int temp[total_subjects][10];
	int time_table[100][10][10];
	dataselection(data_copy,total_subjects,temp);
	while(n<100 && repeat_same_hour_check(temp,data,total_subjects)){
		//printtable(temp,total_subjects,data);
		copy(n,temp,time_table,total_subjects);
		J_hist[n]=cost_compute(temp,total_subjects,data);
		cout<<"\nJ:"<<J_hist[n]<<endl;
		repeat_same_hour(temp,data,total_subjects);
		repeat_same_day(temp,data,total_subjects);
		n++;
	}
	min=J_hist[0];
	pos=0;
	for(i=0;i<100;i++){
		// printtable(time_table[i],total_subjects,data,i);
		if(J_hist[i]<=min){
			min=J_hist[i];
			pos=i;
		}
	}
	//repeat_same_hour(temp,data,total_subjects);
	printtable(time_table[pos],total_subjects,data,pos);
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

void dataselection(int data_copy[][2],int total_subjects,int temp[][10])
{
	int i,j,pos,n;
	n = class_per_day(data_copy,total_subjects);
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
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
int class_per_day(int data_copy[][2],int total_subjects)
{
        int i,m=0;
        for(i=0;i<total_subjects;i++)
                m+=data_copy[i][1];
        m=(m/6)+1;
        return m;
}
int getmax(int data_copy[][2],int total_subjects)
{
	int i,high,pos=0;
	high=data_copy[0][1];
	for(i=0;i<total_subjects;i++)
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

void printtable(int temp[][10],int total_subjects,int data[][2],int num)
{
        int i,j,n;
        n = class_per_day(data,total_subjects);
	cout<<"\t\t\t\t\tTIME TABLE "<<num<<endl;
        cout<<"\t\tMONDAY   TUESDAY  WEDNESDAY   THURSDAY  FRIDAY   SATURDAY\n";
        for(i=0;i<n;i++)
	{
		cout<<"Period : "<<i+1;
		for(j=0;j<6;j++)
       		{
               		cout<<setw(10)<<temp[i][j];

        	}
		cout<<endl;
	}
}

void repeat_same_hour(int temp[][10],int data[][2], int total_subjects){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	for(i=0;i<rows-1;i++){
		for(j=0;j<6;j++){
			for(k=j+1;k<6;k++){
				if(temp[i][j]==temp[i][k]){
					for(l=0;l<rows;l++){
						if(l!=k){
							if(temp[i][j]!=temp[l][k]){
								tempo=temp[i][j];
								temp[i][j]=temp[l][k];
								temp[l][k]=tempo;
							}
						}
					}
				}
			}
		}
	}
}

int repeat_same_hour_check(int temp[][10],int data[][2], int total_subjects){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	for(i=0;i<rows-1;i++){
		for(j=0;j<6;j++){
			for(k=j+1;k<6;k++){
				if(temp[i][j]==temp[i][k]){
					return 1;
				}
			}
		}
	}
	return 0;
}


int repeat_same_day_check(int temp[][10],int data[][2], int total_subjects){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	for(i=0;i<6;i++){
		for(j=0;j<rows;j++){
			for(k=j+1;k<rows;k++){
				if(temp[j][i]==temp[k][i]){
					return 1;
				}
			}
		}
	}
	return 0;
}

void repeat_same_day(int temp[][10],int data[][2], int total_subjects){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	for(i=0;i<6;i++){
		for(j=0;j<rows;j++){
			for(k=j+1;k<rows;k++){
				if(temp[j][i]==temp[k][i]){
					for(l=0;l<6;l++){
						if(i!=l){
							if(temp[k][i]!=temp[k][l]){
								tempo=temp[k][i];
								temp[k][i]=temp[k][l];
								temp[k][l]=tempo;
							}
						}
					}
				}
			}
		}
	}
}

void copy(int i, int temp[10][10],int time_table[][10][10],int total_subjects){
	int j,k;
	for(j=0;j<total_subjects;j++){
		for(k=0;k<6;k++){
			time_table[i][j][k]=temp[j][k];
		}
	}

}

int cost_compute(int temp[10][10],int total_subjects,int data[][2]){
	int cost=0,i,j,k;
	int rows =  class_per_day(data,total_subjects);
	for(i=0;i<6;i++){
		for(j=0;j<rows;j++){
			for(k=j+1;k<rows;k++){
				if(temp[j][i]==temp[k][i]){
					cost+=2;
				}
			}
		}
	}
	for(i=0;i<rows;i++){
		for(j=0;j<6;j++){
			for(k=j+1;k<6;k++){
				if(temp[i][j]==temp[i][k]){
					if(temp[i][j]!=0){
						cost+=1;
					}
				}
			}
		}
	}
	return cost;
}