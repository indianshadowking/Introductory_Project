#include<iostream>
#include<iomanip>
#include<fstream>
#include "header/data.h"
#include "header/costcompute.h"
#include "header/print.h"
#include "header/hour.h"
#include "header/day.h"

using namespace std;

int main(){
	int total_subjects,n=0,min,pos,i,duration,time,temp[total_subjects][10],time_table[150][10][10];
	int J_hist[150];
	cout<<" Enter the total Number of Subjects\n ";
	cin>>total_subjects;
	cout<<" Enter the starting time of Regular class\n ";
	cin>>time;
	cout<<" Enter the duration of each Period\n ";
	cin>>duration;
	int data[total_subjects][2],data_copy[total_subjects][2];
	string name[total_subjects][2],temp_name[total_subjects][10],teacher_name[total_subjects][10];
	getdata(data,data_copy,total_subjects,name);
	printdata(data,total_subjects,name);
	dataselection(data_copy,total_subjects,temp,name,temp_name,teacher_name);
	while(n<150 && repeat_same_hour_check(temp,data,total_subjects) && repeat_same_day_check(temp,data,total_subjects))
	{
		copy(n,temp,time_table,total_subjects);
		J_hist[n]=cost_compute(temp,total_subjects,data);
		repeat_same_hour(temp,data,total_subjects,temp_name,teacher_name);
		repeat_same_day(temp,data,total_subjects,temp_name,teacher_name);
		n++;
	}
	min=J_hist[0];
        pos=0;
        for(i=0;i<n+1;i++){
            if(J_hist[i]<=min){
                min=J_hist[i];
                pos=i;
            }
        }

	printtable(time_table[pos],total_subjects,data,temp_name,pos,time,duration,teacher_name);
	return 0;
}

