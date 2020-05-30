using namespace std;

void pattern();
void printdata(int [][2],int,string [][2]);
void printtable(int [][10],int,int [][2],string [][10],int,int,int,string [][10]);

void printdata(int data[][2],int total_subjects,string name[][2])
{       
	int i;
	cout<<"\tSUBJECTS_CODE\tSUBJECT_CREDIT\tSUBJECT_NAME\t  SUBJECT_TEACHER\n";
        for(i=0;i<total_subjects;i++)
        {       
            cout<<setw(14)<<data[i][0]<<setw(16)<<data[i][1]<<setw(19)<<name[i][0]<<setw(20)<<name[i][1]<<endl;
        }
}

void printtable(int time_table[][10],int total_subjects,int data[][2],string temp_name[][10],int num,int time,int duration,string teacher_name[][10])
{
    int i,j,n,cnt=0;
    n = class_per_day(data,total_subjects);
	pattern();
	int m=class_per_day(data,total_subjects);
	ofstream myfile;
	myfile.open("time_table.csv");
	myfile << endl;
	cout<<"\n\t\t\t\t\tTIME TABLE "<<endl;
	pattern();
	myfile<<","<<"MONDAY"<<","<<"TUESDAY"<<","<<"WEDNESDAY"<<","<<"THURSDAY"<<","<<"FRIDAY"<<","<<"SATURDAY"<<endl;
    cout<<"\n\t\t  MONDAY   TUESDAY   WEDNESDAY   THURSDAY   FRIDAY   SATURDAY\n";
    for(i=0;i<n;i++)
    {
	    if( cnt==0)
	    {
		    cout<<"["<<time<<" to "<<time+duration<<"]";
		    myfile<<endl<< "["<<time<<" to "<<time+duration<<"]"<<endl;
            time++;
	    }
	    if(cnt == 1)
	    {
			cout<<"["<<time<<":30"<<" to "<<time+1<<":30]";
     		myfile<< "["<<time<<":30"<<" to "<<time+1<<":30]"<<endl;
			time++;
	    }
	    cout<<"\nPeriod : "<<i+1;
        myfile << "PERIOD : " << i+1 << ",";
        for(j=0;j<6;j++)
        {
            cout<<setw(11)<<temp_name[i][j];
			myfile << temp_name[i][j] << ",";
        }
		cout<<endl;
		myfile<<endl;
		cout<<"Lecturer :";
		myfile<<"Lecturer: "<<",";
		for(j=0;j<6;j++)
        {
            cout<<setw(11)<<teacher_name[i][j];
            myfile<<teacher_name[i][j]<<",";
		}
		cout<<endl;
		myfile<<endl;
		if(i==1 && n>2)
        {
            cout<<endl;
            pattern();
            cout<<"\n\t\t\t\tSHORT BREAK";
            myfile<<endl<<" ["<<time<<" to "<<time<<":30]"<<",";
            myfile<<"SHORT BREAK"<<","<<"SHORT BREAK"<<","<<"SHORT BREAK"<<","<<"SHORT BREAK";
            myfile<<","<<"SHORT BREAK"<<","<<"SHORT BREAK"<<endl;
			cout<<" ["<<time<<" to "<<time<<":30]";
		    cnt=1;
			cout<<endl;
            pattern();
        }
        if(i==3 && n>4)
        {
            cout<<endl;
			pattern();
			cout<<"\n\t\t\t\tLUNCH BREAK";
			myfile<<endl<<" ["<<time<<":30"<<" to "<<time+1<<":30]";
			myfile<<","<<"LUNCH BREAK"<<","<<"LUNCH BREAK"<<","<<"LUNCH BREAK"<<","<<"LUNCH BREAK";
			myfile<<","<<"LUNCH BREAK"<<","<<"LUNCH BREAK"<<endl;
			cout<<" ["<<time<<":30"<<" to "<<time+1<<":30]";
			time++;
			cnt=1;
			cout<<endl;
			pattern();
        }
        myfile<<endl;
        cout<<endl;
    }
	pattern();
	cout<<endl;
}

void pattern()
{
	int i;
	for(i=0;i<90;i++)
                cout<<"-";
}