using namespace std;

void getdata(int [][2],int [][2], int,string [][2]);
void dataselection(int [][2],int,int [][10],string [][2],string [][10],string [][10]);
int getmax(int [][2],int);
int class_per_day(int [][2],int);

int class_per_day(int data_copy[][2],int total_subjects)
{
    int i,m=0;
    for(i=0;i<total_subjects;i++)
        m+=data_copy[i][1];
    m=(m/6)+1;
    return m;
}

void getdata(int data[][2],int data_copy[][2],int total_subjects,string name[][2])
{
	int i;
	cout<<"\n\t\t\tEnter the details of "<<total_subjects<<"  subjects\n";
	for(i=0;i<total_subjects;i++)
	{
		cout<<"   Enter the subject code for subject "<<i+1<<endl<<"   ";
		cin>>data[i][0];
		data_copy[i][0]=data[i][0];
		cout<<"   Enter the Subject name\n   ";
		cin>>name[i][0];
		cout<<"   Enter the name of Teacher\n   ";
		cin>>name[i][1];
		cout<<"   Enter the credits of subject "<<name[i][0]<<endl<<"   ";
	    cin>>data[i][1];
		data_copy[i][1]=data[i][1];
		cout<<endl;
	}
}

void dataselection(int data_copy[][2],int total_subjects,int temp[][10],string name[][2],string temp_name[][10],string teacher_name[][10])
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
			{
			temp[i][j]=data_copy[pos][0];
			temp_name[i][j]=name[pos][0];
			teacher_name[i][j]=name[pos][1];
			}
		}
	}
			
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